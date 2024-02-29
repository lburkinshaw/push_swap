/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/29 12:17:52 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_node **a, t_node **b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target_node;
	long	best_match;

	curr_b = *b;
	while (curr_b)
	{
		best_match = LONG_MAX;
		curr_a = *a;
		while (curr_a)
		{
			if ((curr_a->num > curr_b->num) && curr_a->num < best_match)
			{
				best_match = curr_a->num;//save num as best match (long)
				target_node = curr_a;//set node as temp target
			}
			curr_a = curr_a->next;//iterate through all nodes in a
		}
		if (best_match == LONG_MAX)//therefore no smaller number found in b
			curr_b->target_node = find_min(*a);//set temp target as highest num in a, completing 'circle'.
		else
			curr_b->target_node = target_node;//if best match found (and saved as target), set b's target node as tempp target
		if (!curr_b->next)
			return ;
		curr_b = curr_b->next;//iterate through all nodes in b
	}
}

void	init_nodes_b(t_node **a, t_node **b)
{
	current_index(*a);
	current_index(*b);
	set_target_b(a, b);
}
