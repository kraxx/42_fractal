/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:38:48 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:50:28 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		i;

	i = 0;
	mem = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!mem)
		return (NULL);
	while (*s1)
		mem[i++] = *s1++;
	while (*s2)
		mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}
