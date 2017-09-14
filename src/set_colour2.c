/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colour2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:51:19 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 01:51:19 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_colour_random(t_m *m)
{
	int i;

	i = -1;
	srand(time(NULL));
	while (++i < GRADIENT)
		m->colour[i] = rand();
}

void	set_colour_bw(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
		m->colour[i] = (i % 2) ? 0xffffff : 0;
}

void	set_colour_wb(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
		m->colour[i] = (i % 2) ? 0 : 0xffffff;
}

void	set_colour_neon_rainbow(t_m *m)
{
	m->colour[0] = 0;
	m->colour[1] = 0xff0000;
	m->colour[2] = 0;
	m->colour[3] = 0xffa500;
	m->colour[4] = 0;
	m->colour[5] = 0xffff00;
	m->colour[6] = 0;
	m->colour[7] = 0x00ff00;
	m->colour[8] = 0;
	m->colour[9] = 0x0000ff;
	m->colour[10] = 0;
	m->colour[11] = 0x4b0082;
	m->colour[12] = 0;
	m->colour[13] = 0x8b008b;
	m->colour[14] = 0;
	m->colour[15] = 0xff00ff;
}

void	set_colour_white_rainbow(t_m *m)
{
	m->colour[0] = 0xffffff;
	m->colour[1] = 0xff0000;
	m->colour[2] = 0xffffff;
	m->colour[3] = 0xffa500;
	m->colour[4] = 0xffffff;
	m->colour[5] = 0xffff00;
	m->colour[6] = 0xffffff;
	m->colour[7] = 0x00ff00;
	m->colour[8] = 0xffffff;
	m->colour[9] = 0x0000ff;
	m->colour[10] = 0xffffff;
	m->colour[11] = 0x4b0082;
	m->colour[12] = 0xffffff;
	m->colour[13] = 0x8b008b;
	m->colour[14] = 0xffffff;
	m->colour[15] = 0xff00ff;
}
