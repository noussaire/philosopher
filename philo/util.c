/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:20:30 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/06 22:00:45 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_data *data, int id, char *msg)
{
	// uint64_t	time;

	// time = ;
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data) == 0)
		printf("%lu %d %s\n", get_time() - get_start_time(data), id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_n_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}

int	nb_meals_option(t_data *data)
{
	if (data->nb_meals > 0)
		return (200);
	return (100);
}
