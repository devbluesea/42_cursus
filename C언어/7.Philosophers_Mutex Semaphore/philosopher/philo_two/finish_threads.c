/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:52:43 by seobaek           #+#    #+#             */
/*   Updated: 2021/01/25 14:52:45 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void		finish_semaphores(t_philo *ph, t_sem *sems)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_close(sems->s_meal);
	sem_close(sems->s_forks);
	sem_close(sems->s_write);
	free(ph);
}
