/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:18:17 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:48:50 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_numpad_1(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0xffffff;
		else if (m->togs->s)
			m->col_2 = 0xffffff;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_2(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0;
		else if (m->togs->s)
			m->col_2 = 0;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_3(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0xb38909;
		else if (m->togs->s)
			m->col_2 = 0xb38909;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_4(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0xffff00;
		else if (m->togs->s)
			m->col_2 = 0xffff00;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}

void	key_fp_numpad_5(t_m *m, int press)
{
	if (press)
	{
		if (m->togs->a)
			m->col_1 = 0xff00ff;
		else if (m->togs->s)
			m->col_2 = 0xff00ff;
		if (m->togs->a || m->togs->s)
		{
			set_colour_gradient(m);
			start_draw(m);
		}
	}
}
