/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:37:43 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/04 16:31:14 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_find_max_min(char ***tab, int k)
{
	int				i;
	int				data;

	i = -1;
	data = 0;
	while ((*tab)[++i])
	{
		if (!k && ft_strcmp((*tab)[i], (*tab)[data]) < 0)
			data = i;
		else if (k && ft_strcmp((*tab)[i], (*tab)[data]) > 0)
			data = i;
	}
	return (data);
}

void				ft_sort_tab(char ***tab)
{
	int				i;
	int				j;
	int				max;

	i = -1;
	while ((*tab)[++i])
	{
		j = i - 1;
		max = ft_find_max_min(tab, 1);
		while (tab[++j])
		{
			if (ft_strcmp((*tab)[j], (*tab)[max]) <= 0)
				max = j;
		}
		ft_swap(&(*tab)[max], &(*tab)[i]);
	}
}
