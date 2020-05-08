/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_words_tables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:40:30 by roliveir          #+#    #+#             */
/*   Updated: 2019/04/26 13:13:11 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_del_words_tables(char ***tab)
{
	char	**tmp;

	if (!tab || !*tab)
		return ;
	tmp = *tab;
	while (**tab)
	{
		ft_strdel(*tab);
		*tab += 1;
	}
	free(tmp);
	tmp = NULL;
}
