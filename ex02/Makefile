NAME		=	a.out
CXX			=	c++
INCLUDE		=	-I./includes
FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf
OUTPUT	=	test/myOutput test/myConstractor

SRC_DIR		=	srcs
SRC			=	main.cpp \
				Fixed.cpp

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR	= objs
OBJS	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(@D)
	$(CXX) $(FLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

test: all
	@ ./$(NAME) 1> test/myOutput 2> test/myConstractor
	@ bash test/test.sh

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(OUTPUT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
