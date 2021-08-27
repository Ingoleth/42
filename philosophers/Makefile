CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -rf
SRCS =	philo/init_threads.c	\
		philo/init.c			\
		philo/main.c			\
		philo/number_checks.c	\
		philo/philosopher.c		\
		philo/utils.c

all: philo/philo

philo/philo: ${SRCS}
	${CC} ${CFLAGS} -I philo ${SRCS} -o philo/philo