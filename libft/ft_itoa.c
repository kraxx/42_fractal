/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:27:14 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 21:30:38 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n)
{
	int size;

	size = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		size;

	sign = (n < 0) ? 1 : 0;
	size = find_size(n);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	if (!n)
	{
		str[0] = '0';
		return (str);
	}
	while (--size > -1)
	{
		if (n % 10 > 0)
			str[size] = (n % 10) + '0';
		else
			str[size] = ((n % 10) * (-1)) + '0';
		n /= 10;
	}
	if (sign)
		str[++size] = '-';
	return (str);
}
