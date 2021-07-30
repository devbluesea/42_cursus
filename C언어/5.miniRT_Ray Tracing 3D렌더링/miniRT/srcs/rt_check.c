/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:55:55 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 20:12:26 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_file_check(char **argv)
{
	int i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			break ;
		i++;
	}
	if (argv[1][i + 1] != 'r' || argv[1][i + 2] != 't')
	{
		ft_printf("%s\n", "Error : .rt file does not exist");
		exit(EXIT_FAILURE);
	}
}
