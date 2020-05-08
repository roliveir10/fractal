/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:38:00 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 21:33:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ms1;
	unsigned char	*ms2;

	ms1 = (unsigned char*)s1;
	ms2 = (unsigned char*)s2;
	i = 0;
	while (ms1[i] == ms2[i] && n--)
	{
		if (ms1[i] == '\0' || ms2 == '\0')
			return (0);
		i++;
	}
	if (!n)
		return (ms1[i - 1] - ms2[i - 1]);
	return (ms1[i] - ms2[i]);
}
