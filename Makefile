# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 12:51:30 by iprokofy          #+#    #+#              #
#    Updated: 2017/10/03 13:18:51 by iprokofy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = main.c\
		lst.c\
		tetrimino.c\
		solve.c\
		libft.c

$(NAME): $(SRC)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(SRC:.c=.o) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
