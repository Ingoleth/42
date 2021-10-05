NAME	= zombie
SRCS	= main.cpp classZombie.cpp
OBJS	= $(SRCS:.cpp=.o)
CXX		= clang++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re:	fclean all