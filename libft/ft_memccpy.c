/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:52:41 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:24:55 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_ui i;

	i = 0;
	while (n--)
	{
		((t_uc *)dest)[i] = ((t_uc *)src)[i];
		if (((t_uc *)src)[i++] == (t_uc)c)
			return (dest + i);
	}
	return (NULL);
}
