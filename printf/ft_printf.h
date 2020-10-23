/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:44:13 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/23 14:38:39 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define TRUE 1
# define FALSE 0
# define PRECISION '.'
# define LEFT_MARGIN '0'
# define RIGHT_MARGIN '-'

typedef struct	s_flags
{
	int			width;
	t_bool		precision;
	int			precision_value;
	int			append;
	int			zeroes;
}				t_printf_list;

int				ft_printf(const char *format_string, ...);
const char		*print_str (const char *s, int *pi);
t_printf_list	*get_flags(const char **s, va_list ap);
void			get_special_flags(const char **s, t_printf_list
				*flags, va_list ap);
int				set_flag_value(const char **s, va_list ap);
char			*handle_conversions(const char **s, va_list ap,
				t_printf_list *flags, int *i);
char			*handle_long_conversions(const char **s, va_list ap);
char			*handle_n(int *i, int *j, t_printf_list *flags);
char			*handle_flags(char *str, t_printf_list *flags,
				char current_type);
char			*handle_appends(char *str, t_printf_list *flags,
				char current_type);
char			*handle_precision(char *str, char current_type, int precision);
char			*precision_special_case(char *string);
char			*handle_precision_string(char *str, int precision);
char			*handle_width_left(char *str, int width);
char			*handle_width_right(char *str, int width);
char			*handle_width_zeroes(char *str, t_printf_list *flags,
				char current_type);
char			*zeroes_special_case(char *str, int zeroes, char current_type);
char			*add_left_zeroes(char *string, int width);
int				print_final(char *str);
int				print_char(const char	**format_string, char *c, int width);
char			*handle_string(char *str);
char			*handle_char(int c);
char			*handle_nmb(int nmb);
char			*handle_long_nmb(long int nmb);
char			*handle_hex(unsigned long int nmb, char c);
char			hex_c(int i, char c);
int				get_hex_lenght(long int nmb);
char			*handle_ptr(char	*ptr, int precision, int prc_bool);
int				ft_findchr(const char *s, int c);
int				ft_power(int root, int exponent);
int				hextoi(char *s);

#endif
