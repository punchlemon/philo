/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:00:06 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/28 16:18:50 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(const int argc, const char **argv)
{
	int		ret;
	t_data	data;
	t_philo	*philos;
	t_fork	*forks;

	ret = 0;
	(void)argv;
	if (argc > 4)
	{
		init_data(&data, argc, argv);
		deb_print_data(data);
		if (init(&ret, data, &philos, &forks))
		{
		}
	}
	else
		return (ft_putendl_fd(2, "Error"), 1);
	destroy(data.num_of_philos, philos, forks);
	return (ret);
}
