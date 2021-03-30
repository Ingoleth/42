/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:14:30 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 18:17:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int get_array_length(int *array)
{
	int i;

	i = 0;

	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}