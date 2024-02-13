/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:03:33 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/13 15:50:31 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dst, t_node **src)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		*dst = push_node;
	}
}

void	pb(t_node **b, t_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

void	pa(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}
