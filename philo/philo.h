/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenasso <nbenasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:50:46 by nbenasso          #+#    #+#             */
/*   Updated: 2024/08/06 21:53:13 by nbenasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				nb_meals_had;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	uint64_t		last_eat_time;

}	t_philo;

typedef struct s_data
{
	int				nb_full_p;
	int				keep_iterating;
	int				nb_philos;
	int				nb_meals;
	uint64_t		die_time;
	uint64_t		eat_time ;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iterating;
	pthread_mutex_t	mut_start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		*philo_ths;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
}	t_data;

void		free_data(t_data *data);
int			nb_meals_option(t_data *data);
int			get_nb_meals_philo_had(t_philo *philo);
void		*all_full_routine(void *data_p);
void		set_keep_iterating(t_data *data, int set_to);
void		*all_alive_routine(void *data_p);
void		sleep_for_eating(t_philo *philo);
int			philo_died(t_philo *philo);
int			get_keep_iter(t_data *data);
int			check_input(int ac, char **av);
int			init_data(t_data *data, int argc, char **argv);
int			ft_atoi(const char *str);
void		print_instruction(void);
int			init_philos(t_data *data);
void		update_last_meal_time(t_philo *philo);
int			get_n_philos(t_data *data);
int			init_forks(t_data *data);
uint64_t	get_time(void);
void		*routine(void *philo_p);
void		ft_usleep(uint64_t sleep_time, t_philo *philo);
t_state		get_philo_state(t_philo *philo);
int			eat(t_philo *philo);
int			take_forks(t_philo *philo);
int			one_philo(t_philo *philo);
uint64_t	get_last_eat_time(t_philo *philo);
int			take_left_fork(t_philo *philo);
uint64_t	get_die_time(t_data *data);
void		set_philo_state(t_philo *philo, t_state state);
void		print_msg(t_data *data, int id, char *msg);
uint64_t	get_start_time(t_data *data);
uint64_t	get_eat_time(t_data *data);
uint64_t	get_sleep_time(t_data *data);
int			ft_sleep(t_philo *philo);
int			think(t_philo *philo);
void	drop_right_fork(t_philo *philo);
#endif