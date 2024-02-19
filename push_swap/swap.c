/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:24:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/16 14:32:42 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node	**stack)
{
	t_node	*new_top;
	t_node	*old_top;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	old_top = *stack;
	new_top = (*stack)->next;
	old_top->next = new_top->next;
	old_top->prev = new_top;
	new_top->next = old_top;
	new_top->prev = NULL;
	*stack = new_top;
}

void	sa(t_node **a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_node **b, int print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}
