/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:43:44 by jchow             #+#    #+#             */
/*   Updated: 2017/07/26 17:42:21 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_atoull_base(const char *str, int base)
{
	t_ull	i;
	t_ull	acc;

	i = 0;
	acc = 0;
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			acc = acc * base + (str[i++] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			acc = acc * base + (str[i++] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			acc = acc * base + (str[i++] - 'A' + 10);
	}
	return (acc);
}
