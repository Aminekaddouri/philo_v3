/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:32:27 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/25 01:17:02 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_grab_fork(t_philo *philo)
{
	sem_wait(philo->fork_sem);
	print_message(philo, "has taken a fork");
	sem_wait(philo->fork_sem);
	print_message(philo, "has taken a fork");
}

void	ft_down_forks(t_philo *philo)
{
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
}

void	ft_sleep_then_think(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	print_message(philo, "is thinking");
}

void	ft_eating(t_philo *philo)
{
	print_message(philo, "is eating");
	gettimeofday(&philo->time, NULL);
	ft_usleep(philo->time_to_eat);
	philo->num_eat_count += 1;
}

void	philo_action(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_monitor, philo))
		print_error("Error: Failed to create the thread");
	if (philo->id % 2 == 1)
		usleep(100);
	while (1)
	{
		ft_grab_fork(philo);
		ft_eating(philo);
		ft_down_forks(philo);
		if (philo->num_each_must_eat != -1
			&& philo->num_eat_count >= philo->num_each_must_eat)
		{
			philo->finished = 1;
			exit(0);
		}
		ft_sleep_then_think(philo);
	}
	if (pthread_join(philo->check_monitor, NULL))
		print_error("Error: Failed to join the thread");
}
