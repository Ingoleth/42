/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:27:19 by user42            #+#    #+#             */
/*   Updated: 2020/09/02 19:47:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*source;
	unsigned int	i;

	i = 0;
	source = (char*)src;
	if (dstsize == 0)
		return (ft_strlen(source));
	if (!dst || !src)
		return (0);
	while (i < dstsize - 1 && source[i])
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(source));
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (*dst && dstsize)
	{
		dst++;
		i++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (len + i);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char			*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;

	i = 0;
	string = (char*)s;
	while (string[i])
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	return (c == '\0') ? (&string[i]) : NULL;
}
