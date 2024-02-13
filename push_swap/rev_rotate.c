/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:15:17 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/13 12:11:30 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_penultimate(t_node *lst)
{
	t_node	*ptr;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	rev_rotate(t_node **stack)
{
	t_node	*last_node;
	t_node	*new_bottom;

	if (!(*stack))
		return ;
	last_node = find_last_node(*stack);
	new_bottom = find_penultimate(*stack);
	last_node->next = *stack;
	*stack = last_node;
	new_bottom->next = NULL;
}

void	rra(t_node **a, int print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}
