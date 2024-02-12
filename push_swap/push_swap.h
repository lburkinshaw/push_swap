/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/12 16:04:13 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>

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
int		check_repeat_stack(t_node *stack);
void	sort_stack(t_node	**stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
int		count_nums(t_node	*stack);
int		check_sorted(t_node	*stack);
void	free_split(char **arguments);
void	free_stack(t_node **stack, int error);
void	error_n_exit(void);
#endif