/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:12:17 by roliveir          #+#    #+#             */
/*   Updated: 2019/05/04 15:47:22 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_getenv(char **env, char *name)
{
	int				i;
	unsigned long	j;

	i = -1;
	if (!name)
		return (NULL);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], name, ft_strlen(name)))
		{
			j = 0;
			while (env[i][j] && env[i][j] != '=')
				j++;
			if (env[i][j] && j == ft_strlen(name))
				return (ft_strdup(&env[i][++j]));
		}
	}
	return (NULL);
}
