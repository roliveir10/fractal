/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 07:02:31 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 07:03:53 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double				ft_clamp(double value, double lo, double hi)
{
	if (value < lo)
		return (lo);
	else if (value > hi)
		return (hi);
	else
		return (value);
}
