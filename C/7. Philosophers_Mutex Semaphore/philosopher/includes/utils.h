/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:58:01 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/16 22:11:11 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_putnbr_fd(unsigned long n, int fd);
int		ft_strlen(const char *str);
void	ft_putstr(const char *str);

#endif
