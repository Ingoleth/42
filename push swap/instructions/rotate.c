/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:21:32 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 02:25:38 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rotate(int *array)
{
	int size;
	int i;
	int aux;

	if (!array || !array[0])
		return ;
	size = get_array_size(array) - 1;
	i = size;
	aux = array[0];
	while (i >= 0)
	{
		array[i] = array[i + 1];
		i--; 
	}
	array[size] = aux;
}