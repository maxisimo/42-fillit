# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 17:03:58 by maxisimo          #+#    #+#              #
#    Updated: 2017/12/12 15:42:59 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = check_sample.c map.c other_functions.c solver.c main.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
