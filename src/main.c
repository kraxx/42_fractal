/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:59:40 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 18:09:25 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	first_step(t_m *m, char *arg)
{
	if (!strcmp(arg, "julia"))
		m->frac = JULIA;
	else if (!strcmp(arg, "mandelbrot"))
		m->frac = MANDEL;
	else if (!strcmp(arg, "ship"))
		m->frac = SHIP;
	else if (!strcmp(arg, "menace"))
		m->frac = MENACE;
	else if (!strcmp(arg, "crevice"))
		m->frac = CREVICE;
	else if (!strcmp(arg, "fish"))
		m->frac = FISH;
	else if (!strcmp(arg, "time"))
		m->frac = TIME;
	else
		return (0);
	init_env(m);
	return (1);
}

static int	write_usage(void)
{
	ft_putstr("usage: ./fractol [ [31mjulia\033[0m | [32mmandelbrot\033[0m "
			"| [33mship\033[0m | [34mmenace\033[0m | [35mcrevice\033[0m | "
			"[36mfish\033[0m | [37mtime\033[0m ]\n\n[33mKEYS:\033[0m\n\n"
			"[36m[↑][↓][←][→][[LEFT CLICK]\033[0m  Translate fractal\n"
			"[36m[RIGHT CLICK]\033[0m              Adjust Z constant\n[36m"
			"[WHEEL UP/DOWN][HOME][END]\033[0m Zoom about mouse cursor\n[36m"
			"[+][-]\033[0m                     Zoom about center\n[36m[*][/]"
			"\033[0m                     Increase/decrease fractal iterations"
			"\n[36m[[][]]\033[0m                     Increase/decrease "
			"window size\n[36m[NUMPAD 0]\033[0m                 Reset image"
			"\n[36m[1-7]\033[0m                      Change fractal\n[36m"
			"[FN][DEL]\033[0m                  Increase/decrease pulse speed"
			"\n[36m[P]\033[0m                        Switch on/cycle through"
			"colour pulsers\n[36m[O]\033[0m                        Switch "
			"off colour\n[36m[A][S] + [NUMPAD 1-9]\033[0m      Set gradient "
			"colour 1/2\n[36m[Z]\033[0m                        Switch on "
			"custom fractal gradient\n[36m[X]\033[0m                        "
			"Cycle fractal contrasted colours\n[36m[C]\033[0m                 "
			"       Cycle fractal smooth colours\n[36m[V]\033[0m              "
			"          Randomize fractal colours\n[36m[ESC]\033[0m            "
			"          Exit program\n");
	return (0);
}

int			main(int ac, char **av)
{
	t_m	m;

	ft_bzero(&m, sizeof(t_m));
	if (ac != 2 || !first_step(&m, av[1]))
		return (write_usage());
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, m.width, m.height, m.name[m.frac]);
	m.togs = (t_togs*)ft_memalloc(sizeof(t_togs));
	m.img = (t_img*)malloc(sizeof(t_img));
	m.img->ptr = mlx_new_image(m.mlx, m.width, m.height);
	m.img->data = (int*)mlx_get_data_addr(m.img->ptr,
			&m.img->bpp, &m.img->size, &m.img->e);
	set_hooks(&m);
	mlx_loop_hook(m.mlx, loop_hook, &m);
	mlx_loop(m.mlx);
	return (1);
}
