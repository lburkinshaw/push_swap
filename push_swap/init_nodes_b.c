/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:49:57 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *a, t_node *b)//sets target in A for each B node: closest higher value.
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*target_node;
	long	best_match;

	curr_b = b;
	while (curr_b)
	{
		best_match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if ((curr_a->num > curr_b->num) && curr_a->num < best_match)//if num in A is greater than B and less than best match (closer to B)
			{
				best_match = curr_a->num;//save num as best match (long)
				target_node = curr_a;//set node as temp target
			}
			curr_a = curr_a->next;//iterate through all nodes in A
		}
		if (best_match == LONG_MAX)//therefore no no. found in A that is bigger than no. in B.
			curr_b->target_node = find_min(a);//set temp target as highest num in A, completing 'circle'.
		else
			curr_b->target_node = target_node;//if best match found (and saved as target), set B's target node as temporary target
		curr_b = curr_b->next;//iterate through all nodes in B
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
