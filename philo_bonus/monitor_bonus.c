/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:08:28 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/22 04:17:37 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_if_somone_died(t_philo *philo)
{
	size_t	time_stamp;

	time_stamp = get_time() - ((philo->time.tv_sec * 1000)
			+ (philo->time.tv_usec / 1000));
	if (time_stamp >= (size_t)philo->time_to_die)
		return (1);
	return (0);
}

void	*check_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_if_somone_died(philo))
		{
			sem_wait(philo->print_sem);
			printf("%lld %d %s\n", \
				get_time() - philo->start_time, philo->id, "died");
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
