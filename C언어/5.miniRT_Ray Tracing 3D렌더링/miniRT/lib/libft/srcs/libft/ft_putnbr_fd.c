/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:37:17 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 14:37:18 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb > 9 || nb < -9)
		ft_putnbr_fd(nb / 10, fd);
	else if (nb < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(nb > 0 ? nb % 10 + 48 : -(nb % 10) + 48, fd);
}
