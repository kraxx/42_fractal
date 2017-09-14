/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:22:45 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:57:51 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_1(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = JULIA;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_2(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = MANDEL;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_3(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = SHIP;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_4(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = MENACE;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}

void	key_fp_5(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_image(m->mlx, m->img->ptr);
		mlx_destroy_window(m->mlx, m->win);
		m->frac = CREVICE;
		m->win = mlx_new_window(m->mlx, m->width, m->height, m->name[m->frac]);
		m->img->ptr = mlx_new_image(m->mlx, m->width, m->height);
		m->img->data = (int*)mlx_get_data_addr(m->img->ptr,
				&m->img->bpp, &m->img->size, &m->img->e);
		set_hooks(m);
		reset_xy(m);
		start_draw(m);
	}
}
