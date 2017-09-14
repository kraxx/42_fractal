/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:56:54 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:14:31 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <math.h>
# include <time.h>
# include <pthread.h>

# define THREAD_COUNT	32
# define ITER			64
# define ITER_INC		4
# define ITER_CAP		2056

# define WIN_WIDTH		1000
# define WIN_HEIGHT		1000
# define WIN_RESIZE		50

# define GRADIENT		16
# define COLOUR_1		0x0f2d4c
# define COLOUR_2		0xc1e0ff
# define PULSE_SPEED	1

# define TRANSLATE		0.1
# define ROT			0.1
# define TRANS_SENS		0.01
# define DRAG_SENS		0.001
# define ZOOM_SENS		0.000325

# define ZOOM_IN		1.1
# define ZOOM_OUT		0.8

# define R_MASK 		0xFF0000
# define G_MASK 		0x00FF00
# define B_MASK 		0x0000FF

# define RED				[31m
# define GREEN				[32m
# define BLUE				[34m
# define YELLOW				[33m
# define MAGENTA			[35m
# define GREY				[37m
# define GREEN_LIGHT		[92m
# define YELLOW_LIGHT		[93m
# define YELLOW_BOLD		[1;33m
# define YELLOW_LIGHT_BOLD	[1;93m
# define MAGENTA_LIGHT		[95m
# define BLINK				[5m
# define GREEN_LIGHT_BLINK	[5;92m
# define END_COLOUR			\033[0m

# define JULIA			1
# define MANDEL			2
# define SHIP			3
# define MENACE			4
# define CREVICE		5
# define FISH			6
# define TIME			7
# define RAY			0

# define SQUARE(x)		(x * x)

typedef struct	s_frac
{
	double	const_re;
	double	const_im;
	double	re1;
	double	im1;
	double	re2;
	double	im2;

}				t_frac;

typedef struct	s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size;
	int				e;
}				t_img;

typedef struct	s_togs
{
	int	up:1;
	int	down:1;
	int	left:1;
	int	right:1;
	int	a:1;
	int	s:1;
	int	numpad_plus:1;
	int	numpad_minus:1;
	int	fn:1;
	int	bk_del:1;
	int	home:1;
	int	end:1;
	int	mouse_left:1;
	int	mouse_right:1;
}				t_togs;

typedef struct	s_master
{
	t_togs	*togs;
	t_img	*img;
	void	*mlx;
	void	*win;
	void	(*pulse_pattern[5])(struct s_master*);
	void	(*colour_bw_preset[4])(struct s_master*);
	void	(*colour_preset[5])(struct s_master*);
	void	(*mouse_fp[6])(struct s_master*, int, int);
	void	(*key_fp[280])(struct s_master*, int);
	int		(*frac_pattern[16])(struct s_master*, int, int);
	char	*name[16];
	int		colour[GRADIENT];
	int		pulse_speed:5;
	int		pulse_speed_switch[5];
	t_ui	pulse_i:3;
	t_ui	preset_i:3;
	t_ui	preset_bw_i:3;
	t_ui	frac:4;
	int		col_1;
	int		col_2;
	int		toggle:1;
	int		pulse:1;
	int		inverted:1;
	int		preset_x_tog:1;
	int		preset_c_tog:1;
	int		iter;
	double	z_re;
	double	z_im;
	double	zoom;
	double	x;
	double	y;
	double	mid_x;
	double	mid_y;
	int		height;
	int		width;
	int		mouse_x;
	int		mouse_y;
	int		mouse_left_x;
	int		mouse_left_y;
	int		mouse_right_x;
	int		mouse_right_y;
}				t_m;

typedef struct	s_view
{
	t_m	*m;
	int	y;
	int	y_lim;
}				t_view;

void			key_fp_numpad_1(t_m *m, int press);
void			key_fp_numpad_2(t_m *m, int press);
void			key_fp_numpad_3(t_m *m, int press);
void			key_fp_numpad_4(t_m *m, int press);
void			key_fp_numpad_5(t_m *m, int press);
void			key_fp_numpad_6(t_m *m, int press);
void			key_fp_numpad_7(t_m *m, int press);
void			key_fp_numpad_8(t_m *m, int press);
void			key_fp_numpad_9(t_m *m, int press);
void			key_fp_numpad_0(t_m *m, int press);
void			key_fp_up(t_m *m, int press);
void			key_fp_down(t_m *m, int press);
void			key_fp_left(t_m *m, int press);
void			key_fp_right(t_m *m, int press);
void			key_fp_plus(t_m *m, int press);
void			key_fp_minus(t_m *m, int press);
void			key_fp_mult(t_m *m, int press);
void			key_fp_div(t_m *m, int press);
void			key_fp_fn(t_m *m, int press);
void			key_fp_del(t_m *m, int press);
void			key_fp_home(t_m *m, int press);
void			key_fp_end(t_m *m, int press);
void			key_fp_p(t_m *m, int press);
void			key_fp_o(t_m *m, int press);
void			key_fp_i(t_m *m, int press);
void			key_fp_a(t_m *m, int press);
void			key_fp_s(t_m *m, int press);
void			key_fp_z(t_m *m, int press);
void			key_fp_x(t_m *m, int press);
void			key_fp_c(t_m *m, int press);
void			key_fp_v(t_m *m, int press);
void			key_fp_1(t_m *m, int press);
void			key_fp_2(t_m *m, int press);
void			key_fp_3(t_m *m, int press);
void			key_fp_4(t_m *m, int press);
void			key_fp_5(t_m *m, int press);
void			key_fp_6(t_m *m, int press);
void			key_fp_7(t_m *m, int press);
void			key_fp_8(t_m *m, int press);
void			key_fp_left_brace(t_m *m, int press);
void			key_fp_right_brace(t_m *m, int press);
void			key_fp_esc(t_m *m, int press);

int				key_press_hook(int keycode, t_m *m);
int				key_release_hook(int keycode, t_m *m);
void			init_key_fp(t_m *m);

int				mouse_press_hook(int keycode, int x, int y, t_m *m);
int				mouse_release_hook(int keycode, int x, int y, t_m *m);
int				mouse_motion_hook(int x, int y, t_m *m);
void			init_mouse_fp(t_m *m);

void			mouse_press_left_click(t_m *m, int x, int y);
void			mouse_press_right_click(t_m *m, int x, int y);
void			mouse_press_scroll_up(t_m *m, int x, int y);
void			mouse_press_scroll_down(t_m *m, int x, int y);

int				loop_hook(t_m *m);
void			set_hooks(t_m *m);

int				f_julia(t_m *m, int x, int y);
int				f_mandel(t_m *m, int x, int y);
int				f_ship(t_m *m, int x, int y);

int				f_crevice(t_m *m, int x, int y);
int				f_menace(t_m *m, int x, int y);
int				f_fish(t_m *m, int x, int y);
int				f_time(t_m *m, int x, int y);
int				f_ray(t_m *m, int x, int y);

void			init_env(t_m *m);

void			pulse_speed_change(t_m *m, int increase);

void			pulse_random(t_m *m);
void			pulse_pastel(t_m *m);
void			pulse_groovy(t_m *m);
void			pulse_dark_rgb(t_m *m);
void			pulse_lame(t_m *m);

void			start_draw(t_m *m);
void			set_colour_gradient(t_m *m);

void			set_colour_cobalt(t_m *m);
void			set_colour_clover(t_m *m);
void			set_colour_cherry(t_m *m);
void			set_colour_fuschia(t_m *m);
void			set_colour_granite(t_m *m);

void			set_colour_bw(t_m *m);
void			set_colour_wb(t_m *m);
void			set_colour_neon_rainbow(t_m *m);
void			set_colour_white_rainbow(t_m *m);
void			set_colour_random(t_m *m);

void			translate_xy(t_m *m, double x, double y);
void			scale_custom(t_m *m, double x, double y, double z);
void			scale_center(t_m *m, double z);
void			reset_xy(t_m *m);

#endif
