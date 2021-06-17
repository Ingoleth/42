# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 09:35:06 by aiglesia          #+#    #+#              #
#    Updated: 2020/12/18 13:35:51 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
BNS = cub3D_bonus
SRCS =	main.c				\
		image.c				\
		pixel_handling.c	\
		get_scale.c			\
		map.c
LIB_DIR = libft/
LIBFT_A = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -I./ -I libft
RM = rm -f
all: ${NAME}
${NAME}:
		make -C ${LIB_DIR}
		cp ${LIB_DIR}${LIBFT_A} .
		${CC} ${CFLAGS} ${SRCS} ${LIBFT_A} ${LIBS} -o ${NAME}
clean:
		make -C ${LIB_DIR} clean
		rm -rf libft.a
		rm -rf cub3d.bmp
fclean: clean

		make -C $(LIB_DIR) fclean
		${RM} ${NAME}
		${RM} ${BNS}
re: fclean all
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus