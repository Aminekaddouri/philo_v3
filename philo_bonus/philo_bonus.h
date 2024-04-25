/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:50:35 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/25 01:03:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				num_philo;
	int				num_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_each_must_eat;
	int				num_eat_count;
	int				finished;
	int				*pid;
	sem_t			*print_sem;
	sem_t			*fork_sem;
	long long int	start_time;
	int				id;
	pthread_t		check_monitor;
	struct timeval	time;
}		t_philo;

void		free_and_close(t_philo *philo);
void		philo_action(t_philo *philo);
void		*check_monitor(void *args);
void		init_and_parse_args(int ac, char **av, t_philo *philo);
void		parsing(t_philo philo, int ac);
void		init_data(t_philo *philo);
void		print_message(t_philo *philo, char *str);
int			ft_usleep(size_t milliseconds);
long long	get_time(void);
int			ft_atoi(const char *str);
void		print_error(char *err);
size_t		ft_strlen(const char *str);

#endif