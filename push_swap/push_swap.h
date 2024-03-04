/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:15 by lburkins         ###   ########.fr       */
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
	int			index;//assign index for position in stack.
	int			push_cost;//assigns cost based on postion of node and its target node in stack.
	int			above_median;//0 = false, 1= true
	int			cheapest;//0 = false, 1= true
	struct node	*target_node;//points to nodes target in other stack (that it shoud be appended above).
	struct node	*next;
	struct node	*prev;
}	t_node;

int		main(int argc, char	*argv[]);

/****************/
/** CREATE_A.C **/
/****************/
void	create_a(int ac, char *av[], t_node **stack);

/*******************/
/** CHECK_VALID.C **/
/*******************/
void	check_valid(char **args, int split_flag);

/******************/
/** SORT_STACK.C **/
/******************/
void	sort_stack(t_node **a, t_node **b);

/**************/
/** ROTATE.C **/
/**************/
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest);

/******************/
/** REV_ROTATE.C **/
/******************/
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest);

/************/
/** SWAP.C **/
/************/
void	sa(t_node **a);
void	sb(t_node **b);
//NEED TO ADD "ss" (swap a and b at same time)??

/************/
/** PUSH.C **/
/************/
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

/**********************/
/** ERROR_HANDLING.C **/
/**********************/
void	error_n_exit(char **arguments, int split_flag);
void	free_split(char **array);
void	free_stack(t_node **stack);

/*******************/
/** STACK_UTILS.C **/
/*******************/
t_node	*find_last_node(t_node *lst);
int		count_nodes(t_node *lst);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

/********************/
/** INIT_NODES_A.C **/
/********************/
void	init_nodes_a(t_node *a, t_node *b);
void	current_index(t_node *stack);
/********************/
/** INIT_NODES_B.C **/
/********************/
void	init_nodes_b(t_node *a, t_node *b);

/************/
/** MOVE.C **/
/************/
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	move_to_top(t_node **stack, t_node *top, char stack_name);
void	put_min_ontop(t_node **stack);

#endif