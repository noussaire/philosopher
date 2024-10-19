/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:59 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/05 18:17:55 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

int	get_keep_iter(t_data *data)
{
	int	keep_iterating;

	pthread_mutex_lock(&data->mut_keep_iterating);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iterating);
	return (keep_iterating);
}

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_t);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_t);
	return (eat_time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_t);
	return (sleep_time);
}
