/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:56:46 by jchow             #+#    #+#             */
/*   Updated: 2017/07/10 23:06:57 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_ec(const char *nptr)
{
	long long	acc;
	int			sign;

	acc = 0;
	sign = 1;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sign = (*nptr == '-') ? -1 : 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		acc = (acc * 10) + *nptr++ - '0';
	if (acc > (long long)2147483647)
		return (-1);
	if (sign && (acc < (long long)-2147483648))
		return (1);
	return (acc * sign);
}
