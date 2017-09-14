/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:21:07 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:54:12 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_p(t_m *m, int press)
{
	if (press)
	{
		if (!m->pulse)
			m->pulse = 1;
		else
			m->pulse_i += (m->pulse_i == 4) ? -4 : 1;
	}
}

void	key_fp_o(t_m *m, int press)
{
	if (press)
		m->pulse = 0;
}

void	key_fp_a(t_m *m, int press)
{
	m->togs->a = press ? 1 : 0;
}

void	key_fp_s(t_m *m, int press)
{
	m->togs->s = press ? 1 : 0;
}
