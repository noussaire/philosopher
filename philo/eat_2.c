/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:59 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/06 22:18:12 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
}

int	take_left_fork(t_philo *philo)
{
	if (philo_died(philo) == 3 || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (philo_died(philo) == 3 || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (get_n_philos(philo->data) == 1)
		return (one_philo(philo));
	if (take_left_fork(philo) != 0)
		return (1);
	if (take_right_fork(philo) != 0)
	{
		drop_left_fork(philo);
		return (1);
	}
	return (0);
}
