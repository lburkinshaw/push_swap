/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:24:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/27 13:29:30 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node	**stack)
{
    if (!stack || !(*stack)->next)
        return;

    t_node *new_top = (*stack)->next;
    t_node *old_top = *stack;

    // Swap the next pointers
    old_top->next = new_top->next;
    if (new_top->next)
        new_top->next->prev = old_top;
    new_top->next = old_top;

    // Update the prev pointer of the new head
    old_top->prev = new_top;
    new_top->prev = NULL;

    // Update the stack pointer
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
