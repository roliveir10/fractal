/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:53:38 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/03 07:45:54 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		get_newline(char **isread, char **line)
{
	int			i;
	char		*temp;

	i = 0;
	while ((*isread)[i] != '\n' && (*isread)[i])
		i++;
	if ((*isread)[i] == '\n')
	{
		if (!(*line = ft_strsub((*isread), 0, i)))
			return (-1);
		if (!(temp = ft_strdup((*isread) + i + 1)))
			return (-1);
		free(*isread);
		*isread = temp;
		if ((*isread)[0] == '\0')
			ft_strdel(isread);
	}
	else if ((*isread)[i] == '\0')
	{
		if (!(*line = ft_strdup((*isread))))
			return (-1);
		ft_strdel(isread);
	}
	return (1);
}

int				get_line(const int fd, char **line, char **isread)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!*isread)
			*isread = ft_strnew(1);
		buf[ret] = '\0';
		if (!(tmp = ft_strjoinf(*isread, buf)))
			return (-1);
		*isread = tmp;
		if (ft_strchr(buf, '\n'))
			return (get_newline(isread, line));
	}
	if (ret == -1)
		return (-1);
	else if (ret == 0 && *isread == NULL)
		return (0);
	return (get_newline(isread, line));
}
