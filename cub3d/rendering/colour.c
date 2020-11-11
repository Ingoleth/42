/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:20:12 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 17:01:42 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

int		get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int		get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}