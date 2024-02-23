/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:38:41 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/22 10:45:42 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	size;

	i = 0;
	if (!a)
		error_n_exit(NULL, 0);
	while ((!check_sorted(*a)) || *b != NULL)
	{
		size = count_nodes(*a);
		ft_printf("%d\n", size);
		while (0 < size-- && (!check_sorted(*a)))
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(b, a, 0);
			else
				ra(a, 0);
		}
		i++;
		size = count_nodes(*b);
		ft_printf("%d\n", size);
		retrieve_stack(*b);
		while (0 < size--)
		{
			if ((((*b)->index >> i) & 1) == 0 && (!check_sorted(*a)))
				rb(b, 0);
			else
				pa(a, b, 0);
		}
	}
}
