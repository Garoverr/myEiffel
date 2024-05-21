##
## PERSO PROJECT, 2024
## myEiffel
## File description:
## Makefile
##

SRC			=	main.cpp								\
				src/Eiffel.cpp							\
				src/Segment.cpp							\

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

CFLAGS		=	-std=c++20 -Wall -Wextra -Werror -g3

OBJ			=	$(SRC:.cpp=.o)

NAME		=	myEiffel

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS) $(SFML_FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re $(NAME)
