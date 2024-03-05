/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:18:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 14:02:30 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_cheapest(t_node *stack)
{
	t_node	*cheapest;
	t_node	*curr;

	cheapest = NULL;
	curr = stack;
	if (!stack)
		error_n_exit(NULL, 0);
	while (curr)
	{
		if (curr->cheapest == 1)
		{
			cheapest = curr;
			break ;
		}
		curr = curr->next;
	}
	return (cheapest);
}

void	move_to_top(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	move_to_top(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	put_min_ontop(t_node **stack)
{
	t_node	*min;

	min = find_min(*stack);
	current_index(*stack);
	while (*stack != min)
	{
		if (min->above_median)
			ra(stack);
		else
			rra(stack);
	}
}
