/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:47:49 by aiglesia          #+#    #+#             */
/*   Updated: 2021/03/31 18:38:12 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** LINE = string to which characters will be added.
**
** ADDENDUM = string from which characters will be inserted.
** (use pointer arithmetics if you want to start inserting with an offset).
**
** INDEX = Marks where in *line the characters will be inserted.
**
** length = how many characters of ADDENDUM will be inserted.
**
** Inserts length characters of addendum in the string line, creating a new one.
** Returns an index pointing to the character after the inserted bit.
**
** NOTES:
** *line is assumed to be malloced.
** Do not use to create a substring of another one. Use strncat_in instead.
*/

int	ft_insert(char **line, char *addendum, unsigned int index,
unsigned int length)
{
	char	*aux;

	if (length < 1 || !addendum || !(*addendum))
		return (index);
	aux = malloc(ft_strlen(*line) + length + 1);
	if (!aux)
		return (0);
	if (index > ft_strlen(*line) + 1)
		return (0);
	ft_strlcpy(aux, *line, index + 1);
	ft_strlcpy(&aux[index], addendum, length + 1);
	ft_strlcpy(&aux[length + index], &(*line)[index],
		ft_strlen(&(*line)[index]) + 1);
	free(*line);
	*line = aux;
	return (index + length);
}
