/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:24:44 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/01 13:22:39 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node	**stack)
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
