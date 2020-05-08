/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:28:02 by roliveir          #+#    #+#             */
/*   Updated: 2019/01/29 18:45:40 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ms1;
	unsigned char	*ms2;

	i = 0;
	ms1 = (unsigned char*)s1;
	ms2 = (unsigned char*)s2;
	while (ms1[i] || ms2[i])
	{
		if (ms1[i] != ms2[i])
			return (ms1[i] - ms2[i]);
		i++;
	}
	return (ms1[i] - ms2[i]);
}
