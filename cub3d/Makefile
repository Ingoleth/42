# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 09:35:06 by aiglesia          #+#    #+#              #
#    Updated: 2020/12/17 00:05:33 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
BNS = a.out
SRCS =	file_reading/add_texture.c					\
		file_reading/check_map_basic_elements.c		\
		file_reading/check_render_data.c			\
		file_reading/fill_render_struct.c			\
		file_reading/handle_map.c					\
		file_reading/read_file_error.c				\
		file_reading/read_file.c					\
		logic/cleanup.c								\
		logic/handle_keys.c							\
		logic/movement.c							\
		logic/screenshot.c							\
		ray_tracing/angle.c							\
		ray_tracing/draw_column.c					\
		ray_tracing/ray_handler.c					\
		ray_tracing/ray_tracing.c					\
		ray_tracing/sprite_drawing.c				\
		ray_tracing/sprite_handling.c				\
		rendering/colour.c							\
		rendering/image_setup.c						\
		rendering/initialize_render.c				\
		rendering/pixel_handling.c					\
		rendering/redraw_screen.c

SRCS_BONUS =	file_reading/add_texture.c						\
				file_reading/handle_map.c						\
				file_reading/read_file_error.c					\
				bonus/file_reading/check_map_basic_elements.c	\
				bonus/file_reading/check_render_data.c			\
				bonus/file_reading/fill_render_struct.c			\
				bonus/file_reading/read_file.c					\
				bonus/logic/change_level.c						\
				bonus/logic/cleanup.c							\
				bonus/logic/handle_keys.c						\
				bonus/logic/movement.c							\
				logic/screenshot.c								\
				bonus/ray_tracing/angle.c						\
				bonus/ray_tracing/draw_column.c					\
				bonus/ray_tracing/draw_floor_ceiling.c			\
				ray_tracing/ray_handler.c						\
				bonus/ray_tracing/ray_tracing.c					\
				bonus/ray_tracing/sprite_drawing.c				\
				ray_tracing/sprite_handling.c					\
				rendering/colour.c								\
				bonus/rendering/cursor.c						\
				rendering/image_setup.c							\
				bonus/rendering/initialize_map_render.c			\
				bonus/rendering/initialize_render.c				\
				bonus/rendering/load_map.c						\
				rendering/pixel_handling.c						\
				bonus/rendering/redraw_screen.c
LIB_DIR = ./libft/
LIBFT_A = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lmlx -lXext -lX11 -lm -I./
RM = rm -f
ECHO = echo
all: ${NAME}
${NAME}:
		make -C ${LIB_DIR}
		cp ${LIB_DIR}${LIBFT_A} .
		${CC} ${CFLAGS} main.c ${SRCS} ${LIBFT_A} ${LIBS}
bonus: ${BNS}
${BNS}:
		make -C ${LIB_DIR}
		cp ${LIB_DIR}${LIBFT_A} .
		${CC} ${CFLAGS} main.c ${SRCS_BONUS} ${LIBFT_A} ${LIBS}
clean:
		make -C ${LIB_DIR} clean
fclean: 

		make -C $(LIB_DIR) fclean
		${RM} ${NAME}
re: fclean all
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus