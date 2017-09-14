/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:45:19 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:45:29 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;

	if (!*needle)
		return (char *)haystack;
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (haystack[i + j] == needle[i] && i + j < n)
		{
			i++;
			if (!needle[i])
				return ((char *)haystack + j);
		}
		j++;
	}
	return (0);
}
