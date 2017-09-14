/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:36:26 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:43:12 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!*needle)
		return (char *)haystack;
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			i++;
			if (!needle[i])
				return (char *)haystack;
		}
		haystack++;
	}
	return (0);
}
