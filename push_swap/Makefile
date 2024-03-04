# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 12:00:18 by lburkins          #+#    #+#              #
#    Updated: 2024/03/04 13:50:01 by lburkins         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -g
############# Delete -g flag before eval!! ###########

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