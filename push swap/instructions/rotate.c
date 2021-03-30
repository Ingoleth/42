/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:21:32 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/30 12:44:47 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rotate(int *array)
{
	int i;
	int aux;

	if (!array || !array[0])
		return ;
	aux = array[0];
	i = 0;
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = aux;
}
