NAME = expert_system

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++11 -g #-Weverything

SRCS =		axiom.class.cpp\
			expert_system.cpp\
			facts.class.cpp\
			formula.class.cpp\
			hub.class.cpp\
			lexer.cpp\
			parser.cpp\
			token.struct.cpp\
			error_handling.cpp

O_FILES = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(O_FILES)

%.o:%.cpp
	$(CC) $(FLAGS) -c -o $@ $^

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
