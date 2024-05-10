/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:24:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:33 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node	**stack)
{
	t_node	*new_top;
	t_node	*old_top;

	if (!*stack || !(*stack)->next)
		return ;
	new_top = (*stack)->next;
	old_top = *stack;
	old_top->next = new_top->next;
	if (new_top->next)
		new_top->next->prev = old_top;
	new_top->next = old_top;
	old_top->prev = new_top;
	new_top->prev = NULL;
	*stack = new_top;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb\n");
}
