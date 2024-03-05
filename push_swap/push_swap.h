/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 14:03:55 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct node
{
	int			num;
	int			index;
	int			push_cost;
	int			above_median;
	int			cheapest;
	struct node	*target_node;
	struct node	*next;
	struct node	*prev;
}	t_node;

int		main(int argc, char	*argv[]);
void	create_a(int ac, char *av[], t_node **stack);
void	check_valid(char **args, int split_flag);
void	sort_stack(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	sa(t_node **a);
void	sb(t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	error_n_exit(char **arguments, int split_flag);
void	free_split(char **array);
void	free_stack(t_node **stack);
t_node	*find_last_node(t_node *lst);
int		count_nodes(t_node *lst);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
void	init_nodes_a(t_node *a, t_node *b);
void	current_index(t_node *stack);
void	init_nodes_b(t_node *a, t_node *b);
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	move_to_top(t_node **stack, t_node *top, char stack_name);
void	put_min_ontop(t_node **stack);

#endif