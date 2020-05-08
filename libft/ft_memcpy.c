/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:19:47 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 18:36:55 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*my_dst;
	char	*my_src;
	size_t	i;

	my_dst = (char*)dst;
	my_src = (char*)src;
	i = 0;
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}
