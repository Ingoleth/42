# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 09:35:06 by aiglesia          #+#    #+#              #
#    Updated: 2020/11/26 10:13:51 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS =	file_reading/add_texture.c					\
		file_reading/check_map_basic_elements.c		\
		file_reading/check_render_data.c			\
		file_reading/fill_render_struct.c			\
		file_reading/handle_map.c					\
		file_reading/read_file_error.c				\
		file_reading/read_file.c					\
		logic/cleanup.c								\
		logic/close_window.c						\
		logic/handle_keys.c							\
		logic/movement.c							\
		ray_tracing/angle.c							\
		ray_tracing/draw_column.c					\
		ray_tracing/ray_handler.c					\
		ray_tracing/ray_tracing.c					\
		ray_tracing/sprite.c						\
		rendering/colour.c							\
		rendering/cursor.c							\
		rendering/image_setup.c						\
		rendering/initialize_render.c				\
		rendering/redraw_screen.c
OBJS = 	*.o
LIB_DIR = ./libft/
LIBFT_A = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lmlx -lXext -lX11 -lm
RM = rm -f
ECHO = echo
all: ${NAME}
${NAME}:
		make -C ${LIB_DIR} bonus
		cp ${LIB_DIR}${LIBFT_A} .
		${CC} ${CFLAGS} main.c ${SRCS} ${LIBFT_A} ${LIBS}
bonus: all

clean:
		make -C ${LIB_DIR} clean
		${RM} ${OBJS}
fclean:	clean

		make -C $(LIB_DIR) fclean
		${RM} ${NAME}
re: fclean all
	clear
	./a.out
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus