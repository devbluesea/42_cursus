/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:10:54 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:10:55 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char
	**cut_in_two(char *s)
{
	int		idx;
	int		i;
	int		j;
	char	**res;

	idx = 0;
	while (s && s[idx] != '=')
		idx++;
	res = malloc(sizeof(char*) * 2);
	res[0] = malloc(idx + 1);
	i = -1;
	while (s[++i] != '=')
		res[0][i] = s[i];
	res[0][i] = '\0';
	res[1] = malloc(ft_strlen(s) - idx);
	j = i;
	while (s[++i] != '\0')
		res[1][i - j - 1] = s[i];
	res[1][i - j - 1] = '\0';
	return (res);
}

void
	init_env_list(char **env)
{
	char		**cut;
	int			i;
	t_minish	*minish;

	minish = get_minish();
	minish->env = 0;
	i = 0;
	while (env[i])
	{
		cut = cut_in_two(env[i]);
		if (i == 0)
			minish->env = lst_new_env(cut[0], cut[1]);
		else
			lst_add_env(minish->env, cut[0], cut[1]);
		free(cut[0]);
		free(cut[1]);
		free(cut);
		i++;
	}
}
