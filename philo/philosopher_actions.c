/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:51:05 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/25 05:00:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_bool	check_philosopher_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->finish_lock);
	if (philo->should_die || philo->data->finish_simulation)
	{
		pthread_mutex_unlock(&philo->data->finish_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->finish_lock);
	return (false);
}

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(60);
	while (true)
	{
		if (check_philosopher_status(philo) == true)
			break ;
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->data->num_philo;
		philo_grap_fork(philo, right_fork);
		if (philo->data->num_philo == 1)
			break ;
		philo_grap_fork(philo, left_fork);
		philo_is_eating(philo);
		philo_put_fork(philo, right_fork, left_fork);
		sleep_then_think(philo);
	}
	return (NULL);
}
