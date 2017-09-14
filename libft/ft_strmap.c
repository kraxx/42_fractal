/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:07:24 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:49:13 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	i = -1;
	while (s[++i])
		map[i] = f(s[i]);
	return (map);
}
