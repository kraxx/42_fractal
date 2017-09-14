/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:46:55 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:47:28 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*start;

	start = dest;
	i = -1;
	while (++i < n)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
	}
	return (start);
}
