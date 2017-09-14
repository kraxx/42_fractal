/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:20:14 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:52:04 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_plus(t_m *m, int press)
{
	m->togs->numpad_plus = press ? 1 : 0;
}

void	key_fp_minus(t_m *m, int press)
{
	m->togs->numpad_minus = press ? 1 : 0;
}

void	key_fp_mult(t_m *m, int press)
{
	if (press)
	{
		if (m->iter < ITER_CAP)
			m->iter += ITER_INC;
	}
}

void	key_fp_div(t_m *m, int press)
{
	if (press)
	{
		if (m->iter > 0)
			m->iter -= ITER_INC;
	}
}
