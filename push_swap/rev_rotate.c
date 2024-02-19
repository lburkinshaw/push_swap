/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:11:22 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/16 14:16:59 by lburkins         ###   ########.fr       */
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
