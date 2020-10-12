/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:38:52 by user42            #+#    #+#             */
/*   Updated: 2020/09/04 13:11:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_copy;

	n_copy = n;
	if (n_copy < 0)
	{
		n_copy = -n_copy;
		ft_putchar_fd('-', fd);
	}
	if (n_copy > 9)
	{
		ft_putnbr_fd(n_copy / 10, fd);
		ft_putchar_fd(n_copy % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n_copy + 48, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
