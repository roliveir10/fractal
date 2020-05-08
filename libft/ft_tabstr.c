/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:58:01 by roliveir          #+#    #+#             */
/*   Updated: 2019/03/15 00:55:06 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_tabstr(char ***str, char c)
{
	char		*fresh;
	int			len;
	int			i;

	len = 0;
	i = -1;
	while ((*str)[++i])
		len += ft_strlen((*str)[i]);
	if (!(fresh = (char*)malloc(sizeof(char) * (len + i + 1))))
		return (NULL);
	fresh[len + i] = '\0';
	i = -1;
	len = 0;
	while ((*str)[++i])
	{
		ft_strcpy(&(fresh[len]), (*str)[i]);
		len += ft_strlen((*str)[i]);
		if ((*str)[i + 1] && (fresh[len] = c))
			len++;
	}
	return (fresh);
}
