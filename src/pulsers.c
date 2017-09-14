/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:28:24 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:06:26 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pulse_random(t_m *m)
{
	int i;

	i = -1;
	srand(time(NULL));
	while (++i < GRADIENT)
		m->colour[i] = rand();
}

void	pulse_pastel(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
	{
		if (((m->colour[i] ^ 0xffff00) < 0x100) && (m->colour[i] & 0xff) > 0)
			m->colour[i] -= 1 * m->pulse_speed;
		else if ((m->colour[i] ^ 0xff0000) < 0x10000 &&
				(m->colour[i] & 0xff) < 0xff)
			m->colour[i] -= 0xff * m->pulse_speed;
		else if ((m->colour[i] & 0xff0000) && (m->colour[i] & 0xff00) < 0xff00)
			m->colour[i] -= 0xff00 * m->pulse_speed;
		else if ((m->colour[i] & 0xff0000) < 0xff0000)
			m->colour[i] += 0xffff * m->pulse_speed;
		else
			m->colour[i] = 0xffffff * m->pulse_speed;
	}
}

void	pulse_groovy(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
	{
		if (((m->colour[i] ^ 0xffff00) < 0x100) && (m->colour[i] & 0xff) > 0)
			m->colour[i] -= 1 * m->pulse_speed;
		else if ((m->colour[i] ^ 0xff0000) < 0x10000 &&
				(m->colour[i] & 0xff00) > 0)
			m->colour[i] -= 0x0100 * m->pulse_speed;
		else if (!(m->colour[i] & 0xffff) && (m->colour[i] > 0))
			m->colour[i] -= 0x10000 * m->pulse_speed;
		else if ((m->colour[i]) < 0xff)
			m->colour[i] += 1 * m->pulse_speed;
		else if ((m->colour[i]) < 0xffff)
			m->colour[i] += 0x100 * m->pulse_speed;
		else if (m->colour[i] < 0xffffff)
			m->colour[i] += 0x10000 * m->pulse_speed;
		else
			m->colour[i] = 0xffffff * m->pulse_speed;
	}
}

void	pulse_dark_rgb(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
	{
		if (m->colour[i] >= 0xffffff)
			m->colour[i] = 0;
		else if (m->colour[i] == 0xffff)
			m->colour[i] = 0x010000;
		else if (m->colour[i] == 0xff)
			m->colour[i] = 0x0100;
		else
		{
			if (m->colour[i] > 0xffff)
				m->colour[i] += 0x010000 * m->pulse_speed;
			else if (m->colour[i] > 0xff)
				m->colour[i] += 0x0100 * m->pulse_speed;
			else
				m->colour[i] += 1 * m->pulse_speed;
		}
	}
}

void	pulse_lame(t_m *m)
{
	int i;

	i = -1;
	while (++i < GRADIENT)
	{
		if (m->colour[i] > 0)
			m->colour[i] -= 1 * m->pulse_speed;
		else
			m->colour[i] += 255 * m->pulse_speed;
	}
	m->toggle = 1;
}
