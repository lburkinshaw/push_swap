/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:18:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/22 16:15:52 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_node *stack)
{
	if (!stack)
		error_n_exit(NULL, 0);
	while (stack)
	{
		if (stack->cheapest == 0)
			stack = stack->next;
	}
	return (stack);
}

void	move_to_top(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)//if both above median, rotate both until on of cheapest reches top/
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))//if both below media, rev rotate both.
		rev_rotate_both(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a, 0);
}

void	move_b_to_a(t_node **a, t_node **b)//this is simpler because only needs to rotate B's target node in a to top and push B to A.
{
	move_to_top(a, (*b)->target_node, 'a');
	pa(a, b, 0);
}

void	put_min_ontop(t_node **stack)
{
	t_node	*min;

	min = find_min(*stack);
	current_index(*stack);
	while (*stack != min)
	{
		if (min->above_median)
			ra(stack, 0);
		else
			rra(stack, 0);
	}
}
