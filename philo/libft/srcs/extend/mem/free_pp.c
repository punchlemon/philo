/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakayam <hnakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:22:48 by retanaka          #+#    #+#             */
/*   Updated: 2024/11/24 14:59:17 by hnakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_pp(char **pp)
{
	size_t	i;

	i = 0;
	while (pp[i])
	{
		free(pp[i]);
		i++;
	}
	free(pp);
}
