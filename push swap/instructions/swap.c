/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:07:37 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 21:18:16 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *array, int length)
{
	int	aux;

	if (array)
	{
		if (length > 1)
		{
			aux = array[0];
			array[0] = array[1];
			array[1] = aux;
		}
	}
}
