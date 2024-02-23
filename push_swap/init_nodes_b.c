/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/23 15:15:14 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_node **a, t_node **b)
{
	t_node	*curr_a;
	t_node	*target_node;
	long	best_match;

	while (*b)
	{
		best_match = LONG_MAX;
		curr_a = *a;
		while (curr_a)
		{
			if ((curr_a->num > (*b)->num) && curr_a->num < best_match)
			{
				best_match = curr_a->num;//save num as best match (long)
				target_node = curr_a;//set node as temp target
			}
			curr_a = curr_a->next;//iterate through all nodes in a
		}
		if (best_match == LONG_MAX)//therefore no smaller number found in b
			(*b)->target_node = find_min(*a);//set temp target as highest num in a, completing 'circle'.
		else
			(*b)->target_node = target_node;//if best match found (and saved as target), set b's target node as tempp target
		*b = (*b)->next;//iterate through all nodes in b
	}
}

/*void	cost_analysis_b(t_node **a, t_node **b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(*a);
	len_b = count_nodes(*b);
	while (*b)
	{
		(*b)->push_cost = (*b)->index;
		if ((*b)->above_median == 0)//if a node is below median, subtract index from length (otherwise push_cost remains its index)
			(*b)->push_cost = len_b - (*b)->index;
		if ((*b)->target_node->above_median == 1)//if target in b is above median, add its index to push_cost
			((*b)->push_cost = (*b)->push_cost + (*b)->target_node->index);
		else// if a target is below median
			((*b)->push_cost = (*b)->push_cost + (len_a - (*b)->target_node->index));
		*b = (*b)->next;
	}
}*/

void	init_nodes_b(t_node **a, t_node **b)
{
	current_index(*a);
	printf("a index: %d\n", (*a)->index);
	current_index(*b);
	printf("b index: %d\n", (*b)->index);
	set_target_b(a, b);
	//printf("b[0] target: %d\n", (*b)->target_node->num);
	/*cost_analysis_b(a, b);
	set_cheapest(a);*/
}
