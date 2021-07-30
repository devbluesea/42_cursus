/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:09:32 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:09:32 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_arg(char **argv, int i, int cnt)
{
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (i < cnt - 1)
			ft_putstr(" ");
		i++;
	}
}

int
	exec_echo(t_cmd *cmd)
{
	int cnt;

	cnt = count_arg(cmd->argv);
	if (cnt > 2 && ft_strequ(cmd->argv[1], "-n"))
		print_arg(cmd->argv, 2, cnt);
	else
	{
		print_arg(cmd->argv, 1, cnt);
		ft_putstr("\n");
	}
	return (EXIT_SUCCESS);
}
