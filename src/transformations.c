/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:53:19 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 01:53:19 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate_xy(t_m *m, double x, double y)
{
	m->x += x / m->zoom;
	m->y += y / m->zoom;
	m->toggle = 1;
}

void	scale_custom(t_m *m, double x, double y, double z)
{
	m->zoom *= z;
	translate_xy(m, x, y);
	m->toggle = 1;
}

void	scale_center(t_m *m, double z)
{
	m->zoom *= z;
	m->toggle = 1;
}

void	reset_xy(t_m *m)
{
	m->zoom = 1;
	m->x = 0;
	m->y = 0;
	m->z_re = 0;
	m->z_im = 0;
	m->mid_x = m->width / 2;
	m->mid_y = m->height / 2;
	m->iter = ITER;
	m->zoom = 1;
	m->toggle = 1;
}

void	pulse_speed_change(t_m *m, int increase)
{
	static int i = 0;

	if (increase && i < 3)
		m->pulse_speed = m->pulse_speed_switch[++i];
	else if (!increase && i > 0)
		m->pulse_speed = m->pulse_speed_switch[--i];
}
