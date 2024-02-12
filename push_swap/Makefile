# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 12:00:18 by lburkins          #+#    #+#              #
#    Updated: 2024/02/12 11:21:10 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES =	push_swap.c \
			init_n_retrieve_stack.c \
			check_valid.c \
			error_handling.c \
			sort_stack.c
			

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: libft $(NAME)

$(NAME): $(CFILES) $(LIBFT)
	cc $(CFLAGS) $(CFILES) $(LIBFT) -o $(NAME)

libft:
	make -C libft

clean:
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all libft clean fclean re