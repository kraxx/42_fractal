/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_f_pointers3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 05:19:40 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 05:51:22 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_fp_up(t_m *m, int press)
{
	m->togs->up = press ? 1 : 0;
}

void	key_fp_down(t_m *m, int press)
{
	m->togs->down = press ? 1 : 0;
}

void	key_fp_left(t_m *m, int press)
{
	m->togs->left = press ? 1 : 0;
}

void	key_fp_right(t_m *m, int press)
{
	m->togs->right = press ? 1 : 0;
}
