/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:10:31 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 21:26:20 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	my_c;
	unsigned char	*my_s;
	size_t			i;

	my_c = (unsigned char)c;
	my_s = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (my_c == my_s[i])
			return (my_s + i);
		i++;
	}
	return (NULL);
}
