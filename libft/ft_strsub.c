/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:22:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 20:57:19 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ms;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ms = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
	{
		ms[i] = s[i + start];
		i++;
	}
	ms[i] = '\0';
	return (ms);
}
