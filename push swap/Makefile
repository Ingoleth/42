# PROGRAM NAME

CHECKER = checker
PUSH_SWAP = push_swap

# HEADER FILES DIRECTORIES

INCLUDES = -Ilibft/ -I.
SRCS_COMMON = 		handle_input/get_array_from_argv.c					\
					handle_input/get_input_array.c						\
					handle_input/get_rand_array.c						\
					handle_input/handle_flags.c							\
					handle_input/handle_input.c							\
					handle_input/initialize_arrays.c					\
					instructions/push.c									\
					instructions/rev_rotate.c							\
					instructions/rotate.c								\
					instructions/swap.c									\
					utils/number_checks.c								\
					utils/print_stacks.c

SRCS_CHECKER = 		checker_main.c										\
					instructions/get_instructions_verbose.c				\
					instructions/get_instructions.c

SRCS_PUSH_SWAP =	push_swap_main.c									\
					sorting/quick_sort/quick_sort.c						\
					sorting/regular_sort/find_smallest_nums_in_path.c	\
					sorting/regular_sort/push_smaller_numbers.c			\
					sorting/regular_sort/regular_sort.c					\
					sorting/sort_3.c									\
					sorting/sort_3_over_stack.c							\
					sorting/sort_5.c									\
					sorting/sort_5_over_stack.c							\
					utils/find_smallest_num.c							\
					utils/get_offset.c									\
					utils/instruction.c									\
					utils/move_to_index.c								\
					utils/print_smaller_nums_found.c					\
					utils/push_num.c

LIBFT_A = libft.a
# COMPILER FLAGS
FLAGS = -Wall -Wextra -Werror -g

all: ${CHECKER}
checker: ${CHECKER}
bonus: all

${CHECKER}: ${SRCS_COMMON} ${SRCS_CHECKER} ${LIBFT_A}
			gcc ${INCLUDES} ${FLAGS} ${SRCS_COMMON} ${SRCS_CHECKER} ${LIBFT_A} -o ${CHECKER}

${PUSH_SWAP}: ${SRCS_COMMON} ${SRCS_PUSH_SWAP} ${LIBFT_A}
			gcc ${INCLUDES} ${FLAGS} ${SRCS_COMMON} ${SRCS_PUSH_SWAP} ${LIBFT_A} -o ${PUSH_SWAP}

${LIBFT_A}:
		make -C libft
		cp libft/libft.a .
clean:
		make -C libft clean
		rm -f *.o
fclean: clean
		make -C libft fclean
		rm -f libft.a
		rm -f ${PUSH_SWAP}
		rm -f ${CHECKER}
re: fclean all checker