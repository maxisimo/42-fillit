# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxisimo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:34:34 by maxisimo          #+#    #+#              #
#    Updated: 2017/12/10 15:09:15 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_lstcount.c ft_lstrev.c ft_find_nbr.c ft_putbase.c ft_search_and_replace.c ft_epur_str.c ft_sort_integer_table.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_lstdel.c ft_lstmap.c ft_lstadd.c ft_lstiter.c ft_putendl.c ft_putstr_fd.c ft_strsplit.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strequ.c ft_strnequ.c ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c ft_strnew.c ft_strdel.c ft_strclr.c ft_putchar.c ft_putstr.c ft_memdel.c ft_memalloc.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_bzero.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_memcmp.c ft_memset.c ft_strcpy.c ft_strncat.c ft_strstr.c ft_atoi.c ft_memccpy.c ft_memcpy.c ft_strcat.c ft_strdup.c ft_strncmp.c ft_isalnum.c ft_memchr.c  ft_memmove.c ft_strcmp.c ft_strlen.c ft_strncpy.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
INCLUDE = libft.h

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
