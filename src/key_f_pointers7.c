/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:21:36 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:55:31 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_z(t_m *m, int press)
{
	if (press)
	{
		m->preset_c_tog = 0;
		m->preset_x_tog = 0;
		set_colour_gradient(m);
		start_draw(m);
	}
}

void	key_fp_x(t_m *m, int press)
{
	if (press)
	{
		m->preset_c_tog = 0;
		if (!m->preset_x_tog)
			m->preset_x_tog = 1;
		else
			m->preset_bw_i += (m->preset_bw_i == 3) ? -3 : 1;
		m->colour_bw_preset[m->preset_bw_i](m);
		start_draw(m);
	}
}

void	key_fp_c(t_m *m, int press)
{
	if (press)
	{
		m->preset_x_tog = 0;
		if (!m->preset_c_tog)
			m->preset_c_tog = 1;
		else
			m->preset_i += (m->preset_i == 4) ? -4 : 1;
		m->colour_preset[m->preset_i](m);
		start_draw(m);
	}
}

void	key_fp_v(t_m *m, int press)
{
	if (press)
	{
		m->preset_c_tog = 0;
		m->preset_x_tog = 0;
		set_colour_random(m);
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
