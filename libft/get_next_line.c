/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:47:27 by oboutrol          #+#    #+#             */
/*   Updated: 2019/06/03 06:13:07 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_printline(int fd, char **stat, char **line)
{
	int		k;
	char	*tmp;

	k = 0;
	while (stat[fd][k] != '\n' && stat[fd][k])
		k++;
	if (stat[fd][k] == '\n')
	{
		*line = ft_strsub(stat[fd], 0, k);
		if ((tmp = ft_strdup(stat[fd] + k + 1)) == NULL)
			return (-1);
		free(stat[fd]);
		stat[fd] = tmp;
		if (stat[fd][0] == '\0')
			ft_strdel(&stat[fd]);
	}
	else if (stat[fd][k] == '\0')
	{
		*line = ft_strdup(stat[fd]);
		ft_strdel(&stat[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stat[1023];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(stat[fd]))
			stat[fd] = ft_strnew(1);
		buff[ret] = '\0';
		if ((tmp = ft_strjoin(stat[fd], buff)) == NULL)
			return (-1);
		free(stat[fd]);
		stat[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			return (ft_printline(fd, stat, line));
	}
	if (ret == -1)
		return (-1);
	else if (ret == 0 && stat[fd] == NULL)
		return (0);
	return (ft_printline(fd, stat, line));
}
