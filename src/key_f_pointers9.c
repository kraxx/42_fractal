/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers9.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:23:32 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:00:10 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_6(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = FISH;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_7(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = TIME;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_left_brace(t_m *m, int press)
{
	if (press && m->width > 50 && m->height > 50)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->width -= WIN_RESIZE;
		m->height -= WIN_RESIZE;
		m->mid_x = m->width / 2;
		m->mid_y = m->height / 2;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		start_draw(m);
	}
}

void	key_fp_right_brace(t_m *m, int press)
{
	if (press && m->width < 2056 && m->height < 2056)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->width += WIN_RESIZE;
		m->height += WIN_RESIZE;
		m->mid_x = m->width / 2;
		m->mid_y = m->height / 2;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		start_draw(m);
	}
}

void	key_fp_esc(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(42);
	}
}
