/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:06:30 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/16 22:06:55 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

static size_t	getlen(int num)
{
	size_t		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void			ft_putnbr_fd(unsigned long n, int fd)
{
	char	line[11];
	size_t	i;

	i = getlen(n);
	line[i] = '\0';
	i--;
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n > 0)
	{
		line[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	ft_putstr_fd(line, fd);
}
