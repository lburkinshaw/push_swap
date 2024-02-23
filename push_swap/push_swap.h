/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/23 13:07:49 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> //Remember to delete for eval

typedef struct node
{
	int			num;
	int			index;
	int			push_cost;
	int			above_median;//0 = false, 1= true
	int			cheapest;//0 = false, 1= true
	struct node	*target_node;
	struct node	*next;
	struct node	*prev;
}	t_node;

int		main(int argc, char	*argv[]);
void	retrieve_stack(t_node *stack);
void	create_a(int ac, char *av[], t_node **stack);
void	add_to_stack(char **arguments, t_node **stack, int split_flag);
int		append_num(int nb, t_node **stack);
void	check_valid(char **args, int split_flag);
int		check_digit(char *str);
int		check_empty(char *str);
//int		check_dups_stack(t_node *stack);
int		check_dups(char **array);
void	sort_stack(t_node **a, t_node **b);
int		check_sorted(t_node *stack);
void	sort_three(t_node **stack);
void	rotate(t_node **stack);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	push(t_node **dst, t_node **src);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **b, t_node **a, int print);
void	error_n_exit(char **arguments, int split_flag);
void	rev_rotate(t_node **stack);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);
void	swap(t_node	**stack);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	free_split(char **array);
void	free_stack(t_node **stack);
t_node	*find_last_node(t_node *lst);
int		count_nodes(t_node *lst);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
void	init_nodes_a(t_node **a, t_node **b);
void	init_nodes_b(t_node **a, t_node **b);
void	set_cheapest(t_node **stack);
void	cost_analysis_a(t_node **a, t_node **b);
void	cost_analysis_b(t_node **a, t_node **b);
void	set_target_a(t_node **a, t_node **b);
void	set_target_b(t_node **a, t_node **b);
void	current_index(t_node *stack);
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	move_to_top(t_node **stack, t_node *top, char stack_name);
t_node	*find_cheapest(t_node *stack);
void	put_min_ontop(t_node **stack);
void	radix_sort(t_node **a, t_node **b); //remove and remove function and file from makefle

#endif