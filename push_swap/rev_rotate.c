/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:22 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/01 13:22:14 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*new_bottom;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	new_bottom = last_node->prev;
	new_bottom->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	last_node->next->prev = last_node;
	*stack = last_node;
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
