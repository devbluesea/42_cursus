/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:10:00 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:10:01 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	print_export(t_env *env)
{
	while (env)
	{
		ft_putstr(env->key);
		if (env->value != NULL)
		{
			ft_putstr("=");
			ft_putstr(env->value);
		}
		ft_putstr("\n");
		env = env->next;
	}
}

static int
	idententifier_error(char *ident)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(ident, 2);
	ft_putstr_fd("': not a valid identifier", 2);
	ft_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}

static void
	check_arg_and_export(t_cmd *cmd, int i, int *ret)
{
	int end;
	int copy;

	end = 0;
	copy = 1;
	if (cmd->argv[i][0] == '\0')
		*ret = idententifier_error(cmd->argv[i]);
	else if (ft_strchr(cmd->argv[i], '='))
	{
		if (cmd->argv[i][0] == '=' && !(copy = 0))
			*ret = idententifier_error(cmd->argv[i]);
		while (cmd->argv[i][end] != '=')
			if (ft_haschr("\"\' ", cmd->argv[i][end++]) && !(copy = 0))
			{
				*ret = idententifier_error(cmd->argv[i]);
				break ;
			}
		if (copy)
		{
			cmd->argv[i][end] = '\0';
			lst_check_and_add_env(cmd->argv[i], &cmd->argv[i][++end]);
		}
	}
	else
		lst_check_and_add_env(cmd->argv[i], NULL);
}

int	exec_export(t_cmd *cmd)
{
	int i;
	int ret;

	i = 0;
	ret = EXIT_SUCCESS;
	if (!cmd->argv[1])
		print_export(get_minish()->env);
	while (cmd->argv[++i])
		check_arg_and_export(cmd, i, &ret);
	return (ret);
}
