/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:02:19 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 14:01:49 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *a, t_node *b)
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
			if ((curr_a->num > curr_b->num) && curr_a->num < best_match)
			{
				best_match = curr_a->num;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == LONG_MAX)
			curr_b->target_node = find_min(a);
		else
			curr_b->target_node = target_node;
		curr_b = curr_b->next;
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
