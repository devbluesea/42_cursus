/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:11:44 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:11:45 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	eof_exit(void)
{
	ft_putstr("\n");
	free_all();
	exit(0);
}

void
	fatal_error_exit(void)
{
	ft_putstr_fd("minishell: fatal error : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	free_all();
	exit(EXIT_FAILURE);
}

void
	get_exit_code(int status, int excode)
{
	if (excode == -1)
	{
		if (WIFEXITED(status))
			get_minish()->excode = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			get_minish()->excode = 128 + WTERMSIG(status);
	}
	else
		get_minish()->excode = excode;
}
