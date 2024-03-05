/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:11:47 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/05 15:09:52 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && argv[1][0] == '\0')
		error_n_exit(NULL, 0);
	create_a(argc, argv, &a);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
