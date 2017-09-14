/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:46:25 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 00:42:22 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*mem;
	int		head;
	int		tail;
	int		i;

	i = -1;
	head = 0;
	tail = 0;
	while (ft_iswhitespace(*(s + ++i)))
		head++;
	while (*(s + i))
	{
		if (ft_iswhitespace(*(s + i)))
			tail++;
		else
			tail = 0;
		i++;
	}
	mem = ft_strnew(ft_strlen(s) - head - tail);
	if (!mem)
		return (NULL);
	return (ft_strncpy(mem, s + head, ft_strlen(s) - head - tail));
}
