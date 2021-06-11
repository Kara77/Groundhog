##
## EPITECH PROJECT, 2019
## Makefile groundhog
## File description:
## makefile
##

NAME=	groundhog

SRCS=	Groundhog.cpp	\
		main.cpp

OBJS=	$(SRCS:.cpp=.o)

CPPFLAGS += -Wall -Wextra -std=c++17

all: $(NAME)

$(NAME): $(OBJS)
	 g++ $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re