/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_static.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:10:42 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:10:44 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minish
	*get_minish(void)
{
	static t_minish	minish;

	return (&minish);
}

char
	**get_built_in(void)
{
	static char *built_in[8] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		NULL
	};

	return (built_in);
}
