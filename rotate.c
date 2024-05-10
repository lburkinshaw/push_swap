/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 14:04:23 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
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

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
