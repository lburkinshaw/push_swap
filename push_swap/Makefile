# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 12:00:18 by lburkins          #+#    #+#              #
#    Updated: 2024/03/07 13:57:06 by lburkins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES =	push_swap.c \
			create_a.c \
			sort_stack.c \
			stack_utils.c \
			check_valid.c \
			error_handling.c \
			rotate.c \
			rev_rotate.c \
			swap.c \
			push.c \
			move.c \
			init_nodes_a.c \
			init_nodes_b.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OFILES)
	cd libft && make all
	cc $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

libft:
	make -C libft

clean:
	rm -f $(OFILES)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
