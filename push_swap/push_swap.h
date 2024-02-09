/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/09 13:25:06 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct Node
{
	int			num;
	struct Node	*next;
}	t_node;

int		main(int argc, char	*argv[]);
void	add_nb(long int nb, t_node **stack);
void	add_args_to_stack(char **arguments, t_node **stack);
void	retrieve_stack(t_node *stack);
t_node	*find_last_node(t_node *lst);
int		initiate_stack_a(int ac, char *av[], t_node **stack);
int		check_valid(char **nums);
int 	check_repeat(char *current, char *next[], int i);
int		check_repeat_stack(t_node *stack);
int		count_strings(char **s);

#endif