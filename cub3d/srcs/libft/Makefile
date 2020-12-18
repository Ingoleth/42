# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 18:09:12 by rprieto-          #+#    #+#              #
#    Updated: 2020/11/28 13:20:17 by aiglesia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
EXTRA = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c ft_calloc.c ft_split.c ft_strjoin.c ft_strmapi.c ft_substr.c ft_strtrim.c ft_isspace.c ft_get_index_of.c ft_checkchar.c	\
		ft_nbrlen.c ft_strncat_in.c get_next_line.c gnl_buffer.c ft_lstadd_back.c ft_lstnew.c ft_lstlast.c ft_lstadd_front.c ft_lstsize.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c ft_lstmove_backwards.c ft_lstmove_forwards.c
OBJS = ${SRCS:.c=.o};
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
all: ${NAME}
${NAME}: ${SRCS}
		${CC} ${CFLAGS} ${SRCS}
		ar rc ${NAME} ${OBJS}
		ranlib ${EXTRA}
clean:
		${RM} ${OBJS}
fclean:	clean
		${RM} ${NAME} ${OBJS}
re: fclean all
.PHONY:     all clean fclean