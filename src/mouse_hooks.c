/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 03:41:34 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:05:26 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press_hook(int keycode, int x, int y, t_m *m)
{
	if (keycode < 6 && x >= 0 && y >= 0 && x <= m->width && y <= m->height)
		m->mouse_fp[keycode](m, x, y);
	return (1);
}

int			mouse_release_hook(int keycode, int x, int y, t_m *m)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		m->togs->mouse_left = 0;
	if (keycode == 2)
		m->togs->mouse_right = 0;
	return (1);
}

int			mouse_motion_hook(int x, int y, t_m *m)
{
	if (x >= 0 && x < m->width && y >= 0 && y < m->height &&
			!m->togs->home && !m->togs->end)
	{
		m->mouse_x = x;
		m->mouse_y = y;
		if (m->togs->mouse_left)
		{
			translate_xy(m, -(x - m->mouse_left_x) * DRAG_SENS,
					-(y - m->mouse_left_y) * DRAG_SENS);
			m->mouse_left_x += x - m->mouse_left_x;
			m->mouse_left_y += y - m->mouse_left_y;
		}
		if (m->togs->mouse_right)
		{
			m->z_re += (x - m->mouse_right_x) * TRANS_SENS;
			m->z_im += (y - m->mouse_right_y) * TRANS_SENS;
			m->mouse_right_x += x - m->mouse_right_x;
			m->mouse_right_y += y - m->mouse_right_y;
			m->toggle = 1;
		}
		if (m->toggle)
			start_draw(m);
	}
	return (1);
}

static void	mouse_protect(t_m *protection, int from, int segfaults)
{
	(void)protection;
	(void)from;
	(void)segfaults;
}

void		init_mouse_fp(t_m *m)
{
	m->mouse_fp[0] = &mouse_protect;
	m->mouse_fp[1] = &mouse_press_left_click;
	m->mouse_fp[2] = &mouse_press_right_click;
	m->mouse_fp[3] = &mouse_protect;
	m->mouse_fp[4] = &mouse_press_scroll_up;
	m->mouse_fp[5] = &mouse_press_scroll_down;
}
