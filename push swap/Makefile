# PROGRAM NAME
NAME = input
# HEADER FILES DIRECTORIES
INCLUDES = -Ilibft/ -I.
SRCS =	handle_input/get_array_from_argv.c		\
		handle_input/get_input_array.c			\
		handle_input/get_rand_array.c			\
		handle_input/handle_flags.c				\
		handle_input/handle_input.c				\
		handle_input/number_checks.c			\
		instructions/get_instructions_verbose.c	\
		instructions/get_instructions.c			\
		instructions/push.c						\
		instructions/rev_rotate.c				\
		instructions/rotate.c					\
		instructions/swap.c						\
		utils/get_array_length.c				\
		utils/print_stacks.c

LIBFT_A = libft.a
# COMPILER FLAGS
FLAGS = -Wall -Wextra -Werror -g

all: ${NAME}
bonus: all

${NAME}: main.c ${SRCS} ${LIBFT_A}
			gcc ${INCLUDES} ${FLAGS} main.c ${SRCS} ${LIBFT_A} -o ${NAME}

${LIBFT_A}:
		make -C libft
		cp libft/libft.a .
clean:
		make -C libft clean
		rm -f *.o
fclean: clean
		make -C libft fclean
		rm -f libft.a
		rm -f ${NAME}
		rm -f debug.out
re: fclean all