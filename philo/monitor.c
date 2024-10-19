/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:46:59 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/06 22:14:31 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	int			result;
	t_data		*data;

	data = philo->data;
	result = 2;
	if (get_time() - get_last_eat_time(philo) >= get_die_time(data))
	{
		set_philo_state(philo, DEAD);
		result = 3;
	}
	return (result);
}

void	notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = get_n_philos(data);
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
		set_philo_state(&philos[i], DEAD);
}

int	is_philo_full(t_data *data, t_philo *philo)
{
	int	result;

	result = 6;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		result = 7;
	return (result);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	i = -1;
	nb_philos = get_n_philos(data);
	while (++i < nb_philos && get_keep_iter(data) == 0)
	{
		if (is_philo_full(data, &data->philos[i]) == 6)
			i = -1;
	}
	if (get_keep_iter(data) == 0)
	{
		set_keep_iterating(data, 1);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = get_n_philos(data);
	i = -1;
	while (++i < nb_philos && get_keep_iter(data) == 0)
	{
		if (philo_died(&philos[i]) == 3 && get_keep_iter(data) == 0)
		{
			print_msg(data, philos[i].id, DIED);
			set_keep_iterating(data, 1);
			notify_all_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(500);
	}
	return (NULL);
}
