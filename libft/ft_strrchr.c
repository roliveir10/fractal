/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:36 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 21:33:26 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strrchr(const char *s, int c)
{
	char			*ms;
	unsigned char	mc;
	int				i;

	ms = (char*)s;
	mc = (unsigned char)c;
	i = 0;
	while (ms[i])
		i++;
	while (i >= 0)
	{
		if (ms[i] == mc)
			return (ms + i);
		i--;
	}
	return (NULL);
}
