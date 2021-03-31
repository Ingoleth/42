/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 02:21:32 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:16:43 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(int *array, int length)
{
	int	i;
	int	aux;

	if (!array || !length)
		return ;
	aux = array[0];
	length--;
	i = 0;
	while (i < length)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = aux;
}
