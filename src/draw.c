/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 03:39:35 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:42:23 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	frac_draw(t_m *m, int y, int y_lim)
{
	int	x;

	while (++y < y_lim)
	{
		x = -1;
		while (++x < m->width)
			m->img->data[x + y * m->img->size / 4] =
				m->colour[m->frac_pattern[m->frac](m, x, y) % GRADIENT];
	}
}

static void	*threader(void *v)
{
	t_view	*view;

	view = (t_view*)v;
	frac_draw(view->m, view->y - 1, view->y_lim);
	return ((void*)view);
}

void		start_draw(t_m *m)
{
	pthread_t	thread[THREAD_COUNT];
	t_view		v[THREAD_COUNT];
	int			y_lim;
	int			i;

	mlx_clear_window(m->mlx, m->win);
	y_lim = m->height / THREAD_COUNT;
	i = -1;
	while (++i < THREAD_COUNT)
	{
		v[i].m = m;
		v[i].y = y_lim * i;
		v[i].y_lim = (i == THREAD_COUNT - 1) ? m->height : v[i].y + y_lim;
		pthread_create(&thread[i], NULL, threader, &v[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, 0, 0);
}

static int	gradient_calc(int col_1, int col_2, int level)
{
	int r;
	int g;
	int b;

	if (!level)
		return (col_1);
	r = (((col_1 & R_MASK) - (col_2 & R_MASK)) >> 16) / GRADIENT * level;
	g = (((col_1 & G_MASK) - (col_2 & G_MASK)) >> 8) / GRADIENT * level;
	b = ((col_1 & B_MASK) - (col_2 & B_MASK)) / GRADIENT * level;
	return (((col_1 >> 16) - r) << 16 | (((col_1 & 0xff00) >> 8) - g)
			<< 8 | (col_1 & 0xff) - b);
}

void		set_colour_gradient(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
		m->colour[i] = gradient_calc(m->col_1, m->col_2, i);
}
