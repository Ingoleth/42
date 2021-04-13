/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_smaller_nums_found.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:04:41 by aiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 20:13:08 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_smaller_nums_found(t_list *smaller_nums)
{
	if (!smaller_nums)
		return ;
	printf("------------\n");
	printf("Destination index = %i\n", ((int *)smaller_nums->content)[2]);
	while (smaller_nums)
	{
		printf("Next number (found at %i): %i\n",
			((int *)smaller_nums->content)[0],
			((int *)smaller_nums->content)[1]);
		smaller_nums = smaller_nums->next;
	}
	printf("------------\n");
}
