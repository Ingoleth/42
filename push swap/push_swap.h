/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:39:46 by aiglesia          #+#    #+#             */
/*   Updated: 2021/06/18 20:51:06 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_flags
{
	t_bool	mode_rand;
	t_bool	mode_input;
	t_bool	mode_fd;
	t_bool	mode_argv;
	t_bool	inst_mode_fd;
	t_bool	verbose;
	t_bool	file_output;
	t_bool	display_operations;
	t_bool	log;
	t_bool	profile;
	t_bool	checker;
	t_bool	push_swap;
	int		index;
}			t_flags;

typedef struct s_array_info
{
	int		*array_a;
	int		*array_b;
	int		array_a_length;
	int		array_b_length;
	int		sorted_elements_a;
	int		array_a_offset;
	int		instruction_counter;
	int		fd;
	int		current_index;
	t_bool	verbose;
	t_bool	display_operations;
	t_bool	log;
	t_bool	profiling;
	t_list	*instructions_list;
}			t_array_info;

typedef enum e_instructions
{
	swap_a,
	swap_b,
	swap_a_and_b,
	push_a,
	push_b,
	rot_a,
	rot_b,
	rot_a_and_b,
	rev_rot_a,
	rev_rot_b,
	rev_rot_a_and_b,
	ascending,
	descending,
	left,
	right,
	bigger,
	smaller,
	array_a,
	array_b
}				t_instructions;

typedef enum e_error_code
{
	not_nb = 1,
	repeated,
	max_int,
}				t_error_code;

/*
** INPUT HANDLING
*/
void			handle_input(int argc, char **argv, t_flags *flags,
					t_array_info *arrays);
void			initialize_arrays(int argc, char **argv, t_array_info *arrays,
					t_flags *flags);
void			get_input_array(int fd, t_array_info *arrays, t_bool verbose);
void			get_rand_array(int length, unsigned short lfsr,
					t_array_info *arrays);
void			get_array_from_argv(char **argv, int argc, int argv_pos,
					t_array_info *arrays);
void			handle_flags(char **argv, t_flags *flags, int *argv_pos);
t_bool			is_number(char *line);
t_bool			is_repeated(int nb, t_list *array_list);
t_bool			is_repeated_array(int nb, int *array, int length);
t_bool			is_long_int(char *input);
t_bool			is_sorted(int *array, int length, int direction);
/*
** INSTRUCTIONS
*/
void			get_instructions(t_array_info *arrays, int fd);
void			get_instructions_verbose(t_array_info *arrays, int fd);
void			instruction(unsigned int instruction, t_array_info *arrays);
void			instruction_verbose(unsigned short instruction,
					t_array_info *arrays);
void			instruction_profiling(unsigned short instruction,
					t_array_info *arrays);
void			push(int *dst, int *src, int *dst_length, int *src_length);
void			rotate(int *array, int length);
void			rev_rotate(int *array, int length);
void			swap(int *array, int length);
/*
** SORTING
*/
void			sort_arrays(t_array_info *arrays);
void			juggle_sort_a(t_array_info *arrays);
void			juggle_sort_b(t_array_info *arrays, t_list *subdivisions);
int				get_pivot(int *array, int start, int end);
int				get_pivot_b(int *array, int start, int end);
void			sort_3_a(t_array_info *arrays, int length);
void			sort_3_b(t_array_info *arrays, int length);
t_bool			can_sort_a(t_array_info *arrays, int
					current_set_size, int i);
int				find_biggest_num_b(t_array_info *arrays, int start, int end);
t_bool			check_special_permutations(t_array_info *arrays, int *current_set_size, int *i, int *j);
void    		profile(char **argv, int argv_pos);
void			push_remaining_elements_to_a(t_array_info *arrays,
					int current_set_size);
void			sort_3(t_array_info *arrays);
void			sort_5(t_array_info *arrays);
/*
**  UTILS 
*/
int				get_offset(t_array_info *arrays, int i);
void			print_stacks(t_array_info *arrays, unsigned short instruction);
void			print_array(t_array_info *arrays);
void			push_num(t_array_info *arrays, int stack, int type);
char			*read_input(int fd);

#endif