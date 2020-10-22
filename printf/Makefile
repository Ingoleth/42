# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 18:09:12 by aiglesia          #+#    #+#              #
#    Updated: 2020/10/21 12:36:11 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXTRA = libftprintf.a
SRCS = ft_printf.c							\
       ft_printf_atoi.c						\
	   ft_printf_compare.c					\
	   ft_printf_libft_string.c				\
	   ft_printf_memory_handling.c			\
	   ft_printf_misc.c 					\
	   ft_printf_write.c					\
	   ft_printf_print.c					\
	   ft_printf_handle_hex.c				\
	   ft_printf_flags.c					\
	   ft_printf_conversion_handler.c		\
	   ft_printf_precision_width_handler.c
OBJS = ${SRCS:.c=.o};
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
ECHO = echo
all: ${NAME}
${NAME}: ${SRCS}
		${CC} ${CFLAGS} ${SRCS}
		ar rc ${NAME} ${OBJS}
		ranlib ${EXTRA}
bonus: all

clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME}
re: fclean 
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus