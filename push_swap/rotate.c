/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:39:43 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/13 11:31:20 by lburkins         ###   ########.fr       */
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
	last_node->next = (*stack);
	last_node->next->next = NULL;
	*stack = new_top;
}

void	ra(t_node **a, int print)//rotate top node in A to bottom of stack and print instruction (if specified).
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}
