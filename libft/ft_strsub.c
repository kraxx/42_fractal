/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:22:55 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:42:50 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, t_ui start, size_t len)
{
	char	*mem;
	t_ui	i;

	i = 0;
	mem = ft_strnew(len);
	if (!mem)
		return (NULL);
	while (i < len)
		mem[i++] = s[start++];
	return (mem);
}
