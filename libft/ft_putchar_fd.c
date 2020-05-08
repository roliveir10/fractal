/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:25:33 by oboutrol          #+#    #+#             */
/*   Updated: 2019/01/29 21:46:47 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void			ft_write_4(wchar_t c, int fd)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	e;
	unsigned char	d;

	d = c % 64 + 128;
	c = c / 64;
	e = c % 64 + 128;
	c = c / 64;
	b = c % 64 + 128;
	a = c / 64 + 192 + 32 + 16;
	write(fd, &a, 1);
	write(fd, &b, 1);
	write(fd, &e, 1);
	write(fd, &d, 1);
}

static void			ft_write_3(wchar_t c, int fd)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	e;

	e = c % 64 + 128;
	c = c / 64;
	b = c % 64 + 128;
	a = c / 64 + 192 + 32;
	write(fd, &a, 1);
	write(fd, &b, 1);
	write(fd, &e, 1);
}

static void			ft_write_2(wchar_t c, int fd)
{
	unsigned char	a;
	unsigned char	b;

	b = c % 64 + 128;
	a = c / 64 + 192;
	write(fd, &a, 1);
	write(fd, &b, 1);
}

void				ft_putchar_fd(wchar_t c, int fd)
{
	if (c < 128)
	{
		write(fd, &c, 1);
		return ;
	}
	if (c < 2048)
	{
		ft_write_2(c, fd);
		return ;
	}
	if (c < 16777216)
	{
		ft_write_3(c, fd);
		return ;
	}
	ft_write_4(c, fd);
	return ;
}
