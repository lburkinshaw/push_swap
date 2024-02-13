/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:13 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/13 13:19:02 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node	**stack)
{
	t_node	*new_top;
	t_node	*old_top;

	old_top = *stack;
	new_top = old_top->next;
	old_top->next = new_top->next;
	new_top->next = old_top;
	*stack = new_top;
}

void	sa(t_node **a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}
