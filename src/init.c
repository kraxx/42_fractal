/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 03:31:05 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 03:31:05 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_pulse_speed_switch(t_m *m)
{
	m->pulse_speed_switch[0] = 1;
	m->pulse_speed_switch[1] = 3;
	m->pulse_speed_switch[2] = 5;
	m->pulse_speed_switch[3] = 15;
}

static void	init_colour_presets(t_m *m)
{
	m->colour_preset[0] = &set_colour_cobalt;
	m->colour_preset[1] = &set_colour_clover;
	m->colour_preset[2] = &set_colour_cherry;
	m->colour_preset[3] = &set_colour_fuschia;
	m->colour_preset[4] = &set_colour_granite;
	m->colour_bw_preset[0] = &set_colour_bw;
	m->colour_bw_preset[1] = &set_colour_wb;
	m->colour_bw_preset[2] = &set_colour_neon_rainbow;
	m->colour_bw_preset[3] = &set_colour_white_rainbow;
}

static void	init_func_ptr(t_m *m)
{
	m->pulse_pattern[0] = &pulse_pastel;
	m->pulse_pattern[1] = &pulse_groovy;
	m->pulse_pattern[2] = &pulse_dark_rgb;
	m->pulse_pattern[3] = &pulse_lame;
	m->pulse_pattern[4] = &pulse_random;
	m->frac_pattern[JULIA] = &f_julia;
	m->frac_pattern[MANDEL] = &f_mandel;
	m->frac_pattern[SHIP] = &f_ship;
	m->frac_pattern[MENACE] = &f_menace;
	m->frac_pattern[CREVICE] = &f_crevice;
	m->frac_pattern[FISH] = &f_fish;
	m->frac_pattern[TIME] = &f_time;
	m->frac_pattern[RAY] = &f_ray;
}

static void	init_name(t_m *m)
{
	m->name[JULIA] = ft_strdup("JULIA");
	m->name[MANDEL] = ft_strdup("MANDELBROT");
	m->name[SHIP] = ft_strdup("BURNING SHIP");
	m->name[MENACE] = ft_strdup("PASS INTO THE IRIS");
	m->name[CREVICE] = ft_strdup("DON'T GET LOST :3");
	m->name[FISH] = ft_strdup("GLUG GLUG");
	m->name[TIME] = ft_strdup("DUDUDUDUDU");
	m->name[RAY] = ft_strdup("STINGS LIKE A BEE");
}

void		init_env(t_m *m)
{
	m->iter = ITER;
	m->pulse_speed = PULSE_SPEED;
	m->col_1 = COLOUR_1;
	m->col_2 = COLOUR_2;
	m->width = WIN_WIDTH;
	m->height = WIN_HEIGHT;
	m->mid_x = m->width / 2;
	m->mid_y = m->height / 2;
	m->zoom = 1;
	init_name(m);
	init_func_ptr(m);
	init_colour_presets(m);
	init_pulse_speed_switch(m);
	init_mouse_fp(m);
	init_key_fp(m);
	set_colour_gradient(m);
}
