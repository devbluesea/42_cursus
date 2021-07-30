/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:10:27 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:10:27 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void
	free_tokens(void)
{
	char	**tokens;
	int		i;

	tokens = get_minish()->tokens;
	if (tokens)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
		get_minish()->tokens = 0;
	}
}

void
	free_line(void)
{
	if (get_minish()->line)
		free(get_minish()->line);
	get_minish()->line = NULL;
}

static void
	free_rdir(t_cmd *cmd)
{
	t_rdir *tmp;

	tmp = cmd->in;
	while (cmd->in)
	{
		free(cmd->in->file);
		tmp = cmd->in->next;
		free(cmd->in);
		cmd->in = tmp;
	}
	tmp = cmd->out;
	while (cmd->out)
	{
		free(cmd->out->file);
		tmp = cmd->out->next;
		free(cmd->out);
		cmd->out = tmp;
	}
}

void
	free_cmd(void)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;

	free_line();
	free_tokens();
	cmd = get_minish()->cmd;
	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->argv)
		{
			i = -1;
			while (cmd->argv[++i])
				free(cmd->argv[i]);
			free(cmd->argv);
		}
		free_rdir(cmd);
		free(cmd);
		cmd = tmp;
	}
	get_minish()->cmd = 0;
}
