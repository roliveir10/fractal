/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:28 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 21:33:14 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strchr(const char *s, int c)
{
	unsigned char	mc;
	char			*ms;
	int				i;

	mc = (unsigned char)c;
	ms = (char*)s;
	i = 0;
	while (ms[i])
	{
		if (ms[i] == mc)
			return (ms + i);
		i++;
	}
	if (mc == '\0')
		return (ms + i);
	return (NULL);
}
