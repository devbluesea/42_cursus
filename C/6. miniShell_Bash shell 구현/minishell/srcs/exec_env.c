/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:09:37 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:09:37 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_env(t_env *env)
{
	while (env)
	{
		if (env->value != NULL)
		{
			ft_putstr(env->key);
			ft_putstr("=");
			ft_putstr(env->value);
			ft_putstr("\n");
		}
		env = env->next;
	}
}

int
	exec_env(t_cmd *cmd)
{
	(void)cmd;
	print_env(get_minish()->env);
	return (EXIT_SUCCESS);
}
