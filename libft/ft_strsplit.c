/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:51:02 by jchow             #+#    #+#             */
/*   Updated: 2017/06/08 01:01:46 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_alloc(char const *str, char delim, int i, char **arr)
{
	int	len;
	int	space;

	space = 0;
	len = 0;
	while (*str == delim)
	{
		str++;
		space++;
	}
	while (str[len] && str[len] != delim)
		len++;
	if (len > 0)
	{
		arr[i] = ft_strnew(len);
		ft_strncpy(arr[i], str, len);
	}
	return (space + len);
}

static int	word_count(char const *str, char delim)
{
	int	words;

	words = 0;
	while (*str)
	{
		if (*str++ == delim)
		{
			words++;
			while (*str == delim)
				str++;
		}
	}
	if (*--str != delim)
		words++;
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	words = word_count(s, c);
	arr = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
		s += word_alloc(s, c, i++, arr);
	return (arr);
}
