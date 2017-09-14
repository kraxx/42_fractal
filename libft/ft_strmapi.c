/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:04:37 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:48:43 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	i = -1;
	while (s[++i])
		map[i] = f(i, s[i]);
	return (map);
}
