/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:10:09 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:10:10 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_pwd(t_cmd *cmd)
{
	char cwd[PATH_MAX];

	(void)cmd;
	if (!(getcwd(cwd, sizeof(cwd))))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr(cwd);
	ft_putstr("\n");
	return (EXIT_SUCCESS);
}
