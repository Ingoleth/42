/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rand_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:48:50 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_power(int root, int exp)
{
	if (exp <= 0)
		return (1);
	return (root * ft_power(root, exp - 1));
}

int	rand_num(unsigned short *lfsr, unsigned int *bit, int length)
{
	int	nb;

	if (length > 5)
		length = 0;
	if (length < 1)
		length = 1;
	length = ft_power(10, length);
	*bit = ((*lfsr >> 0) ^ (*lfsr >> 2) ^ (*lfsr >> 3) ^ (*lfsr >> 5)) & 1;
	*lfsr = (*lfsr >> 1) | (*bit << 15);
	nb = *lfsr;
	while (nb > length)
		nb /= 10;
	return (nb);
}

void	get_rand_array(int length, unsigned short lfsr, t_array_info *arrays)
{
	int				i;
	int				nb_length;
	int				sign;
	unsigned int	bit;

	arrays->array_a = ft_calloc(length + 1, sizeof(int));
	if (arrays->array_a == NULL)
		return ;
	i = 0;
	while (i < length)
	{
		nb_length = rand_num(&lfsr, &bit, 3);
		sign = rand_num(&lfsr, &bit, 3);
		if (sign % 2)
			nb_length *= -1;
		if (!is_repeated_array(nb_length, arrays->array_a, i))
		{
			arrays->array_a[i] = nb_length;
			i++;
		}
	}
	arrays->array_a_length = length;
}
