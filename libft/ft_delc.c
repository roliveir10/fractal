/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 04:37:44 by roliveir          #+#    #+#             */
/*   Updated: 2019/03/14 04:46:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_delc(char **str)
{
	int				len;
	char			*fresh;

	len = ft_strlen(*str);
	if (len < 1)
		return (NULL);
	if (!(fresh = ft_strnew(len - 1)))
		return (NULL);
	ft_strncpy(fresh, *str, len - 1);
	ft_strdel(str);
	return (fresh);
}
