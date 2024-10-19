/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:20:30 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/05 18:18:34 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->data), philo);
	set_philo_state(philo, DEAD);
	pthread_mutex_unlock(philo->left_f);
	return (1);
}

void	ft_usleep(uint64_t sleep_time, t_philo *philo)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
	{
		if (get_philo_state(philo) == DEAD)
			break ;
		usleep(500);
	}
}

uint64_t	get_time(void)
{
	struct timeval	tm;

	if (gettimeofday(&tm, NULL))
		return (0);
	return ((tm.tv_sec * (uint64_t)1000) + (tm.tv_usec / 1000));
}
