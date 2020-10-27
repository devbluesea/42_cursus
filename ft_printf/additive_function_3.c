/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additive_function_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:37:55 by seobaek           #+#    #+#             */
/*   Updated: 2020/08/10 20:58:50 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_base(long long n, const char *base)
{
	long long		div;
	int				len;
	long long		base_len;
	char			*ret;

	div = (n < 0) ? -n : n;
	len = (n <= 0) ? 1 : 0;
	base_len = (long long)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	if (n <= 0)
		ret[0] = (n == 0) ? '0' : '-';
	while (n != 0)
	{
		len--;
		ret[len] = (n > 0) ? base[(n % base_len)] : base[-(n % base_len)];
		n = n / base_len;
	}
	return (ret);
}

char	*ft_lltoa(long long n)
{
	long long	div;
	int			len;
	char		*res;

	div = n;
	len = (n <= 0) ? 1 : 0;
	while (div != 0)
	{
		div = div / 10;
		len++;
	}
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	if (n <= 0)
		res[0] = (n == 0) ? '0' : '-';
	while (n != 0)
	{
		len--;
		res[len] = (n > 0) ? (n % 10) + '0' : -(n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

int		ft_putchar_n(char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
		i += ft_putchar(c);
	return (n);
}

int		ft_putstr_n(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
