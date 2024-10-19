NAME = philo

CC = cc 

# CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =  set_1.c monitor.c eat_2.c routine.c parsing.c \
		util.c philo.c init_data.c eat_1.c get_1.c get_2.c time.c \
		thinking.c sleep.c \

OBJS = ${SRCS:.c=.o}


$(NAME): ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all