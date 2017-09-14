/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 20:22:30 by jchow             #+#    #+#             */
/*   Updated: 2017/06/25 23:19:28 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	move_line(char **theo, char **line, int fd, int ret)
{
	char	*temp;
	int		len;

	len = 0;
	while (theo[fd][len] && theo[fd][len] != '\n')
		len++;
	if (theo[fd][len] == '\n')
	{
		*line = ft_strsub(theo[fd], 0, len);
		temp = ft_strdup(theo[fd] + len + 1);
		free(theo[fd]);
		theo[fd] = temp;
	}
	else if (!theo[fd][len])
	{
		if (ret == BUFF_SIZE)
			return (0);
		*line = ft_strdup(theo[fd]);
		free(theo[fd]);
		theo[fd] = NULL;
	}
	return (1);
}

int			ft_get_next_line(const int fd, char **line)
{
	static char	*theo[255];
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!theo[fd])
			theo[fd] = ft_strnew(0);
		buf[ret] = '\0';
		temp = ft_strjoin(theo[fd], buf);
		free(theo[fd]);
		theo[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!theo[fd] || !theo[fd][0]))
		return (0);
	return (move_line(theo, line, fd, ret));
}
