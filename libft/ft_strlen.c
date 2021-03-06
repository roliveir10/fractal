/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:36:22 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 20:50:33 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	int		i;
	char	*m_str;

	m_str = (char*)str;
	i = 0;
	while (m_str[i])
	{
		i++;
	}
	return (i);
}
