/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:06:45 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:06:46 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd > 0)
	{
		if (n < 0)
			write(fd, "-", 1);
		num = (n < 0) ? -n : n;
		if (num < 10)
			ft_putchar_fd(num + '0', fd);
		else
		{
			ft_putnbr_fd(num / 10, fd);
			ft_putchar_fd(num % 10 + '0', fd);
		}
	}
}
