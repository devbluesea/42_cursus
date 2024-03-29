/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:48:58 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/25 14:56:28 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utils.h"

# define ALIVE 0
# define DIED 1
# define FULL 2
# define WRITABLE 1
# define NORMAL 1
# define FOR_PHILOS_ORDERING 20

typedef struct		s_semaphore
{
	sem_t	*s_forks;
	sem_t	*s_write;
	sem_t	*s_meal;
}					t_sem;

typedef struct		s_philo_data
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_of_must_eat;
	int		state;
	long	num_of_meals;
}					t_pd;

typedef struct			s_philo
{
	pthread_t			thread;
	t_sem				*sems;
	t_pd				*pd;
	int					philo_idx;
	long				last_meal;
	long				program_start;
}						t_philo;

int						input_args(t_pd *pd, const char **argv);

t_philo					*init_threads(t_pd *pd, t_sem *sems);
int						init_sems(t_sem *sems, t_pd *pd);

void				finish_semaphores(t_philo *ph, t_sem *sems);

void				grab_fork(t_philo *ph);
void				eating(t_philo *tmp_ph);

void				*is_die(void *tmp_ph);
void				*is_full(void *tmp_ph);

long				get_time(void);
int					messages(const char *str, t_philo *ph);
#endif
