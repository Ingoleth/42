# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 18:09:12 by aiglesia          #+#    #+#              #
#    Updated: 2020/10/23 12:56:24 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXTRA = libftprintf.a
SRCS =	ft_printf_conversion_handler.c		\
		ft_printf_flags.c					\
		ft_printf_handle_hex.c				\
		ft_printf_misc.c 					\
		ft_printf_precision_width_handler.c \
		ft_printf_print.c					\
	    ft_printf.c							
OBJS = ${SRCS:.c=.o};
LIB_DIR = ./Libft/
LIBFT_A = libft.a
LIBFT_BONUS = ft_lstadd_back_bonus.o ft_lstnew_bonus.o ft_lstlast_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o ft_lstclear_bonus.o ft_lstmap_bonus.o
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
ECHO = echo
all: ${NAME}
${NAME}: ${OBJS}
		make -C ${LIB_DIR}
		cp ${LIB_DIR}${LIBFT_A} .
		mv ${LIBFT_A} ${NAME}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
bonus: all

clean:
		make -C ${LIB_DIR} clean
		${RM} ${OBJS}
fclean:	clean

		${RM} ${LIBFT_BONUS}
		${RM} ${LIB_DIR}${LIBFT_A}
		${RM} ${NAME}
re: fclean 
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus