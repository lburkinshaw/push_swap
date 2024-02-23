/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:22 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/22 16:09:49 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*new_bottom;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	new_bottom = last_node->prev;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
	new_bottom->next = NULL;
}

void	rra(t_node **a, int print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_node)
		rrr(a, b, 0);
	current_index(*a);//refresh indexes after operation.
	current_index(*b);
}
