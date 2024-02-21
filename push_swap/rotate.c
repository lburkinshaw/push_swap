/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/20 14:53:05 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*new_top;

	if (!(*stack))
		return ;
	last_node = find_last_node(*stack);
	new_top = (*stack)->next;
	new_top->prev = NULL;
	last_node->next = (*stack);
	*stack = new_top;
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
