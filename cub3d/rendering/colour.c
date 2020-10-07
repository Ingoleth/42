/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:20:12 by user42            #+#    #+#             */
/*   Updated: 2020/10/02 22:33:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_rgb(int t, int r, int g, int b)
{
	int rgb;
	unsigned char *aux;

	aux = (unsigned char*)&rgb;
	*aux = t;
	aux++;
	*aux = r;
	aux++;
	*aux = g;
	aux++;
	*aux = b;
	return (rgb);
}

int		get_t(int trgb)
{
	unsigned char *aux;

	aux = (unsigned char*)&trgb;
	return (*aux);
}

int		get_r(int trgb)
{
	unsigned char *aux;

	aux = (unsigned char*)&trgb;
	return (*(aux + 1));
}

int		get_g(int trgb)
{
	unsigned char *aux;

	aux = (unsigned char*)&trgb;
	return (*(aux + 2));
}

int		get_b(int trgb)
{
	unsigned char *aux;

	aux = (unsigned char*)&trgb;
	return (*(aux + 3));
}

