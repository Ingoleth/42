/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprieto- <rprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:44:29 by rprieto-          #+#    #+#             */
/*   Updated: 2019/11/28 13:05:20 by rprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int n)
{
	long	nbr;
	int		len;

	len = 0;
	nbr = (n < 0) ? -n : n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
