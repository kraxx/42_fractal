/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:20:38 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:53:32 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_fn(t_m *m, int press)
{
	if (press)
		pulse_speed_change(m, 1);
}

void	key_fp_del(t_m *m, int press)
{
	if (press)
		pulse_speed_change(m, 0);
}

void	key_fp_home(t_m *m, int press)
{
	m->togs->home = press ? 1 : 0;
}

void	key_fp_end(t_m *m, int press)
{
	m->togs->end = press ? 1 : 0;
}
