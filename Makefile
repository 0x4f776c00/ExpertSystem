NAME = expert_system

CC = clang++

FLAGS = -Wall -Wextra -Werror #-Weverything

FILES =		axiom.class\
			expert_system\
			facts.class\
			formula.class\
			hub.class\
			parser\

SRCS =		$(addsuffix .cpp, $(FILES))

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(addsuffix .o, $(FILES))

clean:
	rm -f $(addsuffix .o, $(FILES))

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
