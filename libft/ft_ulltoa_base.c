/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 22:51:42 by jchow             #+#    #+#             */
/*   Updated: 2017/06/26 23:25:29 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(t_ull n, int base)
{
	int size;

	size = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

char		*ft_ulltoa_base(t_ull n, int base)
{
	char	master[16];
	char	*str;
	int		size;

	ft_strcpy(master, "0123456789abcdef");
	size = find_size(n, base);
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
		str[size] = master[n % base];
		n /= base;
	}
	return (str);
}
