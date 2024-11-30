/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:51 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/30 18:16:04 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	int				ret;
	struct timeval	tv;

	philo->status = EATING;
	ret = gettimeofday(&tv, NULL);
	if (ret != 0)
		return (ft_putendl_fd(2, "gettimeofday failed"), ret);
	printf("%ld %d eating\n", tv.tv_usec, philo->i);
	philo->last_eat_usec = tv.tv_usec;
	return (0);
}

int	philo_think(t_philo *philo)
{
	int				ret;
	struct timeval	tv;

	ret = gettimeofday(&tv, NULL);
	if (ret != 0)
		return (ft_putendl_fd(2, "gettimeofday failed"), ret);
	printf("%ld %d\n", tv.tv_usec, philo->i);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	int				ret;
	struct timeval	tv;

	ret = gettimeofday(&tv, NULL);
	if (ret != 0)
		return (ft_putendl_fd(2, "gettimeofday failed"), ret);
	printf("%ld %d\n", tv.tv_usec, philo->i);
	return (0);
}

void	*philo_life(void *arg)
{
	int		ret;
	void	*retval;
	t_philo	*philo;

	(void)retval;
	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->i % 2)// 奇数の人は食べても問題ない
			ret = philo_eat(philo);
		else
			philo_think(philo);
		philo_sleep(philo);
		if (ret != 0)
			return ((void *)NULL);// (void *)retだとエラーが出た
	}
	return ((void *)0);
}
