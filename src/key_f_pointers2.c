/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:18:49 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:50:29 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_numpad_6(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0x00ffff;
		else if (m->togs->s)
			m->col_2 = 0x00ffff;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_7(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0xff0000;
		else if (m->togs->s)
			m->col_2 = 0xff0000;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_8(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0x00ff00;
		else if (m->togs->s)
			m->col_2 = 0x00ff00;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_9(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0x0000ff;
		else if (m->togs->s)
			m->col_2 = 0x0000ff;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_0(t_m *m, int press)
{
	if (press)
		reset_xy(m);
}
