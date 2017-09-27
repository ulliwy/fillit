NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)
		
$(NAME):
	gcc  $(FLAGS) $(SRC) -o $(NAME) -L. -lft

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all