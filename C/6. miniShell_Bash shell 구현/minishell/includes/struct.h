/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:04:51 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/13 21:19:35 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_rdir
{
	char			*file;
	int				fd;
	int				is_dbl;
	int				std;
	struct s_rdir	*next;
}					t_rdir;

typedef struct		s_cmd
{
	char			**argv;
	int				is_pipe;
	int				is_rdir;
	int				has_path;
	t_rdir			*in;
	t_rdir			*out;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_minish
{
	char			*line;
	char			**tokens;
	t_env			*env;
	t_cmd			*cmd;
	int				executed;
	int				excode;
	int				eof;
	int				ret;
}					t_minish;

#endif
