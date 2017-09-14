/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:33:27 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:03:03 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press_hook(int keycode, t_m *m)
{
	if (keycode < 280)
		m->key_fp[keycode](m, 1);
	return (1);
}

int			key_release_hook(int keycode, t_m *m)
{
	if (keycode < 280)
		m->key_fp[keycode](m, 0);
	return (1);
}

void		key_protect(t_m *prevents, int segfaults)
{
	(void)prevents;
	(void)segfaults;
}

static void	init_key_fp2(t_m *m)
{
	m->key_fp[KEY_P] = &key_fp_p;
	m->key_fp[KEY_O] = &key_fp_o;
	m->key_fp[KEY_A] = &key_fp_a;
	m->key_fp[KEY_S] = &key_fp_s;
	m->key_fp[KEY_Z] = &key_fp_z;
	m->key_fp[KEY_X] = &key_fp_x;
	m->key_fp[KEY_C] = &key_fp_c;
	m->key_fp[KEY_V] = &key_fp_v;
	m->key_fp[KEY_ESC] = &key_fp_esc;
	m->key_fp[KEY_1] = &key_fp_1;
	m->key_fp[KEY_2] = &key_fp_2;
	m->key_fp[KEY_3] = &key_fp_3;
	m->key_fp[KEY_4] = &key_fp_4;
	m->key_fp[KEY_5] = &key_fp_5;
	m->key_fp[KEY_6] = &key_fp_6;
	m->key_fp[KEY_7] = &key_fp_7;
	m->key_fp[KEY_BRACE_L] = &key_fp_left_brace;
	m->key_fp[KEY_BRACE_R] = &key_fp_right_brace;
	m->key_fp[KEY_FN] = &key_fp_fn;
	m->key_fp[KEY_DEL] = &key_fp_del;
	m->key_fp[KEY_HOME] = &key_fp_home;
	m->key_fp[KEY_END] = &key_fp_end;
}

void		init_key_fp(t_m *m)
{
	int	i;

	i = -1;
	while (++i < 280)
		m->key_fp[i] = &key_protect;
	m->key_fp[KEY_UP] = &key_fp_up;
	m->key_fp[KEY_DOWN] = &key_fp_down;
	m->key_fp[KEY_LEFT] = &key_fp_left;
	m->key_fp[KEY_RIGHT] = &key_fp_right;
	m->key_fp[KEY_NUM_0] = &key_fp_numpad_0;
	m->key_fp[KEY_NUM_1] = &key_fp_numpad_1;
	m->key_fp[KEY_NUM_2] = &key_fp_numpad_2;
	m->key_fp[KEY_NUM_3] = &key_fp_numpad_3;
	m->key_fp[KEY_NUM_4] = &key_fp_numpad_4;
	m->key_fp[KEY_NUM_5] = &key_fp_numpad_5;
	m->key_fp[KEY_NUM_6] = &key_fp_numpad_6;
	m->key_fp[KEY_NUM_7] = &key_fp_numpad_7;
	m->key_fp[KEY_NUM_8] = &key_fp_numpad_8;
	m->key_fp[KEY_NUM_9] = &key_fp_numpad_9;
	m->key_fp[KEY_PLUS] = &key_fp_plus;
	m->key_fp[KEY_MINUS] = &key_fp_minus;
	m->key_fp[KEY_MULTIPLY] = &key_fp_mult;
	m->key_fp[KEY_DIVIDE] = &key_fp_div;
	init_key_fp2(m);
}
