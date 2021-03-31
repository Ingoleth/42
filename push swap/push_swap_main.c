/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:23:42 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 12:55:09 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*array_a;
	int		*array_b;

	if (argc == 1)
		return (0);
	initialize_arrays(argc, argv, &array_a, &array_b);
	bubble_sort(array_a, array_b, 0);
	free(array_a);
	free(array_b);
}
