NAME	=	megaphone
CXX		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)
RM		=	rm -rf

YELLOW	=	\033[1;33m
GREEN	=	\033[1;32m
RESET	=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CXX) $(FLAGS) -c $< -o $@

test: all
	@ echo "$(YELLOW) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~test~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(RESET)"
	@ echo "$(GREEN) test1 $(RESET)"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@ echo "$(GREEN) \n test2$(RESET)"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@ echo "$(GREEN) \n test3$(RESET)"
	./$(NAME)
	@ echo "$(YELLOW) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ $(RESET)"

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all test clean fclean re
