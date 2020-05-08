/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:54:05 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 21:25:56 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*m_dst;
	unsigned char	*m_src;
	unsigned char	m_c;
	unsigned int	i;

	m_dst = (unsigned char*)dst;
	m_src = (unsigned char*)src;
	m_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		m_dst[i] = m_src[i];
		if (m_src[i] == m_c)
			return (m_dst + i + 1);
		i++;
	}
	return (NULL);
}
