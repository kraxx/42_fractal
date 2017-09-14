/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 00:49:43 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 01:02:13 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	t_ui	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	while (*src && i + 1 < size)
		dest[i++] = *src++;
	dest[i] = '\0';
	if (dest_len > size)
		return (src_len + size);
	return (src_len + dest_len);
}
