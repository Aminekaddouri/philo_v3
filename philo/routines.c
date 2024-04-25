/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:59:15 by akaddour          #+#    #+#             */
/*   Updated: 2024/04/22 02:02:49 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_grap_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->data->forks[fork]);
	print_message(philo, "has taken a fork");
}

void	philo_is_eating(t_philo *philo)
{
	print_message(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal = get_time();
	philo->eat_count++;
	if (philo->eat_count == philo->data->num_each_must_eat)
	{
		pthread_mutex_lock(&philo->data->all_ate_lock);
		philo->data->all_ate++;
		pthread_mutex_unlock(&philo->data->all_ate_lock);
	}
	pthread_mutex_unlock(&philo->data->last_meal_lock);
}

void	philo_put_fork(t_philo *philo, int right_fork, int left_fork)
{
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
}

void	sleep_then_think(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_message(philo, "is thinking");
}
