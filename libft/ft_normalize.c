/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 01:46:56 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:24:38 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

t_vector			ft_normalize(t_vector v)
{
	double			r;

	r = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (ft_vdiv(v, r));
}
