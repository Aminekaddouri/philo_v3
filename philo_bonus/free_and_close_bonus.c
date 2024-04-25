/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:26:38 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/20 04:35:29 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_and_close(t_philo *philo)
{
	int		i;
	int		status;

	i = 0;
	while (i < philo->num_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < philo->num_philo)
				kill(philo->pid[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(philo->print_sem);
	sem_close(philo->fork_sem);
	sem_unlink("/print_sem");
	sem_unlink("/fork_sem");
	free(philo->pid);
	free(philo);
}
