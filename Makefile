NAME = expert_system

INCLUDES_DIR = ./includes/
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++11 -g

SRCS_FILES =	axiom.class.cpp\
				expert_system.cpp\
				fact.class.cpp\
				formula.class.cpp\
				hub.class.cpp\
				lexer.cpp\
				parser.cpp\
				token.struct.cpp\
				error_handling.cpp\
				solve_system.cpp

OBJS_FILES = $(SRCS_FILES:.cpp=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDES_DIR)


clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
