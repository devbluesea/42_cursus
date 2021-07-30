/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:03:55 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/25 15:05:00 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		finish_threads(t_philo *ph, t_mutex *mutexes, t_pd *pd)
{
	int i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		pthread_mutex_destroy(&(mutexes->m_forks)[i]);
		i++;
	}
	pthread_mutex_destroy(&(mutexes->m_write));
	pthread_mutex_destroy(&(mutexes->m_state));
	pthread_mutex_destroy(&(mutexes->m_num_of_meals));
	free(ph);
	free(mutexes->m_forks);
}
