/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:20:49 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 22:21:50 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	char			*tab;
	unsigned int	m;
	int				k;

	k = ft_count_n(n);
	m = n < 0 ? -n : n;
	if (!(tab = (char*)malloc(sizeof(char) * k + 1)))
		return (NULL);
	tab[k] = '\0';
	while (k)
	{
		k--;
		tab[k] = m % 10 + '0';
		m = m / 10;
	}
	if (n < 0)
		tab[k] = '-';
	return (tab);
}
