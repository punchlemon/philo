/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:46:13 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/28 16:18:24 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DIED 3

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

// structs
typedef struct s_data
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}	t_data;

typedef pthread_mutex_t	t_fork;

typedef struct s_philo
{
	pthread_t	tid;
	int			i;
	int			status;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		data;
	suseconds_t	last_eat_usec;
}	t_philo;

// functions
// deb
void	deb_ft_put_argv_fd(const int fd, const int argc, const char **argv);
void	deb_print_data(t_data data);
// destroy
void	destroy(int num_of_forks, t_philo *philos, t_fork *forks);

// init
int		init_philos(int *ret, t_data data, t_philo **philos, t_fork *forks);
int		init_forks(int *ret, int num_of_forks, t_fork **forks);
void	init_data(t_data *data, int argc, const char **argv);
int		init(int *ret, t_data data, t_philo ** philos, t_fork **forks);
// life
void	*philo_life(void *arg);


#endif
