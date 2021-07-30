/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:55:03 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/25 14:56:38 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>
#include "utils.h"

# define ALIVE 0
# define DIED 1
# define FULL 2
# define FOR_PHILOS_ORDERING 20

typedef struct		s_mutexes
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_state;
	pthread_mutex_t	m_num_of_meals;
}					t_mutex;

typedef struct		s_philo_date
{
	int				num_of_philo;
	int				num_of_must_eat;
	int				state;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_of_meals;
}					t_pd;

typedef struct		s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*m_left_fork;
	pthread_mutex_t	*m_right_fork;
	t_mutex			*mutex;
	t_pd			*pd;
	int				philo_idx;
	long			last_meal;
	long			program_start;
}					t_philo;

//	input_args.c
int					input_args(t_pd *pd, const char **argv);

//	init.c
t_philo				*init_threads(t_pd *pd, t_mutex *mutexes);
int					init_mutexes(t_mutex *mutexes, t_pd *pd);

//	finish_threads.c
void				finish_threads(t_philo *ph, t_mutex *mutexes, t_pd *pd);

//	doing.c
void				grab_fork(t_philo *ph);
void				eating(t_philo *tmp_ph);

//	monitoring.c
void				*is_die(void *tmp_ph);
void				*is_full(void *tmp_ph);

//	main.c
long				get_time(void);
int					messages(const char *str, t_philo *ph);

#endif
