/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/26 11:45:16 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*new_top;
	t_node	*old_top;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	old_top = *stack;
	new_top = (*stack)->next;
	last_node->next = old_top;
	*stack = (*stack)->next;
	new_top->prev = NULL;
	old_top->prev = last_node;
	old_top->next = NULL;
}

void	ra(t_node **a, int print)//rotate top node in A to bottom of stack and print instruction (if specified).
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node **b, int print)//rotate top node in B to bottom of stack and print instruction (if specified).
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)//makes sure cheapest nodes aren't already at the top, and rotates both untl one of the cheapest  nodes is
		rr(a, b, 0);
	current_index(*a);//refresh indexes after operation.
	current_index(*b);
}