/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 03:27:53 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:45:53 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	f_julia(t_m *m, int x, int y)
{
	t_frac	f;
	int		iter;

	f.re2 = (x - m->mid_x) / (0.5 * m->zoom * m->width) + m->x;
	f.im2 = (y - m->mid_y) / (0.5 * m->zoom * m->height) + m->y;
	iter = -1;
	while (++iter < m->iter)
	{
		f.re1 = f.re2;
		f.im1 = f.im2;
		f.re2 = SQUARE(f.re1) - SQUARE(f.im1) + m->z_re;
		f.im2 = 2 * f.re1 * f.im1 + m->z_im;
		if ((SQUARE(f.re2) + SQUARE(f.im2)) > 4)
			break ;
	}
	return (iter);
}

int	f_mandel(t_m *m, int x, int y)
{
	t_frac	f;
	int		iter;

	f.const_re = (x - m->width * 3 / 4) / (0.5 * m->zoom * m->width) + m->x;
	f.const_im = (y - m->mid_y) / (0.5 * m->zoom * m->height) + m->y;
	f.re2 = m->z_re;
	f.im2 = m->z_im;
	iter = -1;
	while (++iter < m->iter)
	{
		f.re1 = f.re2;
		f.im1 = f.im2;
		f.re2 = SQUARE(f.re1) - SQUARE(f.im1) + f.const_re;
		f.im2 = 2 * f.re1 * f.im1 + f.const_im;
		if (SQUARE(f.re2) + SQUARE(f.im2) > 4)
			break ;
	}
	return (iter);
}

int	f_ship(t_m *m, int x, int y)
{
	t_frac	f;
	int		iter;

	f.const_re = (x - m->width * 2 / 3) / (0.3 * m->zoom * m->width) + m->x;
	f.const_im = (y - m->height * 2 / 3) / (0.3 * m->zoom * m->height) + m->y;
	f.re2 = m->z_re;
	f.im2 = m->z_im;
	iter = -1;
	while (++iter < m->iter)
	{
		f.re1 = f.re2;
		f.im1 = f.im2;
		f.re2 = SQUARE(f.re1) - SQUARE(f.im1) + f.const_re;
		f.im2 = 2 * fabs(f.re1 * f.im1) + f.const_im;
		if (SQUARE(f.re2) + SQUARE(f.im2) > 4)
			break ;
	}
	return (iter);
}
