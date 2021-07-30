/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:03:50 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/25 15:04:35 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->m_right_fork);
	pthread_mutex_lock(ph->m_left_fork);
	messages(" has take a fork\n", ph);
	ph->last_meal = get_time();
	messages(" is eating\n", ph);
	usleep(ph->pd->time_to_eat);
	pthread_mutex_lock(&ph->mutex->m_num_of_meals);
	ph->pd->num_of_meals++;
	pthread_mutex_unlock(&ph->mutex->m_num_of_meals);
	pthread_mutex_unlock(ph->m_left_fork);
	pthread_mutex_unlock(ph->m_right_fork);
}
