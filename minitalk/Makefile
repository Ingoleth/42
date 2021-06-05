# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 18:09:12 by rprieto-          #+#    #+#              #
#    Updated: 2021/06/03 20:32:05 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c
CFLAGS = -Wall -Werror -Wextra -I libft
RM = rm -rf
all: server client
server.o:
		${CC} ${CFLAGS} main_server.c
		mv -f main_server.o ./objs
server: server.o
		gcc ${CFLAGS} objs/main_server.o libft.a -o server
client.o:
		${CC} ${CFLAGS} main_client.c
		mv -f main_client.o ./objs
client: client.o
		gcc ${CFLAGS} objs/main_client.o libft.a -o client
clean:
		${RM} objs/main_*.o
fclean:	clean
		${RM} server
		${RM} client
		${RM} libft.a
re: fclean all
.PHONY:     all re clean fclean server client