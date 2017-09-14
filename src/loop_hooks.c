/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 03:44:58 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:07:51 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	expose_hook(t_m *m)
{
	m->toggle = 0;
	start_draw(m);
	return (1);
}

static int	exit_hook(t_m *m)
{
	mlx_destroy_window(m->mlx, m->win);
	exit(42);
}

int			loop_hook(t_m *m)
{
	m->toggle = 0;
	if (m->togs->up)
		translate_xy(m, 0, m->inverted ? TRANSLATE : -TRANSLATE);
	if (m->togs->down)
		translate_xy(m, 0, m->inverted ? -TRANSLATE : TRANSLATE);
	if (m->togs->left)
		translate_xy(m, m->inverted ? TRANSLATE : -TRANSLATE, 0);
	if (m->togs->right)
		translate_xy(m, m->inverted ? -TRANSLATE : TRANSLATE, 0);
	if (m->togs->numpad_plus)
		scale_center(m, ZOOM_IN);
	if (m->togs->numpad_minus)
		scale_center(m, ZOOM_OUT);
	if (m->togs->home)
		scale_custom(m, (m->mouse_x - m->mid_x) * ZOOM_SENS,
				(m->mouse_y - m->mid_y) * ZOOM_SENS, ZOOM_IN);
	if (m->togs->end)
		scale_custom(m, -(m->mouse_x - m->mid_x) * ZOOM_SENS,
				-(m->mouse_y - m->mid_y) * ZOOM_SENS, ZOOM_OUT);
	if (m->pulse)
		m->pulse_pattern[m->pulse_i](m);
	if (m->toggle || m->pulse)
		start_draw(m);
	return (1);
}

void		set_hooks(t_m *m)
{
	mlx_hook(m->win, 12, 0, expose_hook, m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	mlx_hook(m->win, 3, 0, key_release_hook, m);
	mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	mlx_hook(m->win, 5, 0, mouse_release_hook, m);
	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
	mlx_hook(m->win, 17, 0, exit_hook, m);
}
