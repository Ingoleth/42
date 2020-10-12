/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_memory_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:36:12 by user42            #+#    #+#             */
/*   Updated: 2020/09/02 19:49:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (!s1) ? (char*)s2 : (char*)s1;
	if (!(joined_str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
	* sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined_str[j++] = s2[i++];
	joined_str[j] = '\0';
	return (joined_str);
}

char	*ft_strdup(const char *s1)
{
	char *string;
	char *new_string;

	if (!s1)
		return (0);
	string = (char*)s1;
	if (!(new_string = (char*)malloc((ft_strlen(string) + 1) * sizeof(char))))
		return (NULL);
	else
		return (ft_memcpy(new_string, string, ft_strlen(string) + 1));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pointer;

	pointer = (unsigned char*)b;
	while (len > 0)
	{
		*(pointer++) = (unsigned char)c;
		len--;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned int	i;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;

	if (!(array = malloc(count * size)))
		return (NULL);
	if ((int)count == 0 || (int)size == 0)
		return (array);
	ft_bzero(array, count * size);
	return ((void*)array);
}
