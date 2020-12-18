# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 09:35:06 by aiglesia          #+#    #+#              #
#    Updated: 2020/12/18 12:55:07 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BNS = cub3D_bonus
SRCS =	srcs/file_reading/add_texture.c					\
		srcs/file_reading/check_map_basic_elements.c	\
		srcs/file_reading/check_render_data.c			\
		srcs/file_reading/fill_render_struct.c			\
		srcs/file_reading/handle_map.c					\
		srcs/file_reading/read_file_error.c				\
		srcs/file_reading/read_file.c					\
		srcs/logic/cleanup.c							\
		srcs/logic/handle_keys.c						\
		srcs/logic/movement.c							\
		srcs/logic/screenshot.c							\
		srcs/ray_tracing/angle.c						\
		srcs/ray_tracing/draw_column.c					\
		srcs/ray_tracing/ray_handler.c					\
		srcs/ray_tracing/ray_tracing.c					\
		srcs/ray_tracing/sprite_drawing.c				\
		srcs/ray_tracing/sprite_handling.c				\
		srcs/rendering/colour.c							\
		srcs/rendering/image_setup.c					\
		srcs/rendering/initialize_render.c				\
		srcs/rendering/pixel_handling.c					\
		srcs/rendering/redraw_screen.c					\
		srcs/main.c

SRCS_BONUS =	srcs/file_reading/add_texture.c								\
				srcs/bonus/file_reading/handle_map_bonus.c					\
				srcs/file_reading/read_file_error.c							\
				srcs/bonus/file_reading/check_map_basic_elements_bonus.c	\
				srcs/bonus/file_reading/check_render_data_bonus.c			\
				srcs/bonus/file_reading/fill_render_struct_bonus.c			\
				srcs/bonus/file_reading/read_file_bonus.c					\
				srcs/bonus/logic/change_level_bonus.c						\
				srcs/bonus/logic/cleanup_bonus.c							\
				srcs/bonus/logic/handle_keys_bonus.c						\
				srcs/bonus/logic/movement_bonus.c							\
				srcs/logic/screenshot.c										\
				srcs/bonus/ray_tracing/angle_bonus.c						\
				srcs/bonus/ray_tracing/draw_column_bonus.c					\
				srcs/bonus/ray_tracing/draw_floor_ceiling_bonus.c			\
				srcs/ray_tracing/ray_handler.c								\
				srcs/bonus/ray_tracing/ray_tracing_bonus.c					\
				srcs/bonus/ray_tracing/sprite_drawing_bonus.c				\
				srcs/ray_tracing/sprite_handling.c							\
				srcs/rendering/colour.c										\
				srcs/bonus/rendering/cursor_bonus.c							\
				srcs/rendering/image_setup.c								\
				srcs/bonus/rendering/initialize_map_render_bonus.c			\
				srcs/bonus/rendering/initialize_render_bonus.c				\
				srcs/bonus/rendering/load_map_bonus.c						\
				srcs/rendering/pixel_handling.c								\
				srcs/bonus/rendering/redraw_screen_bonus.c					\
				srcs/main.c
LIB_DIR = ./srcs/libft/
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
		${CC} ${CFLAGS} ${SRCS} ${LIBFT_A} ${LIBS} -o cub3d
bonus: ${BNS}
${BNS}:
		make -C ${LIB_DIR}
		cp ${LIB_DIR}${LIBFT_A} .
		${CC} ${CFLAGS} ${SRCS_BONUS} ${LIBFT_A} ${LIBS} -o cub3d_bonus
clean:
		make -C ${LIB_DIR} clean
		rm -rf libft.a
		rm -rf cub3d.bmp
fclean: clean

		make -C $(LIB_DIR) fclean
		${RM} ${NAME}
re: fclean all
echo: 
		${ECHO} ${SRCS}
.PHONY:     all clean fclean bonus