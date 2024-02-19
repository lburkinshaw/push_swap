/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:11:47 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/19 11:22:26 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retrieve_stack(t_node *stack)//DELETE BEFORE SUBMIT
{
	t_node	*ptr;

	if (stack == NULL)
		return ;
	ptr = stack;
	while (ptr)
	{
		ft_printf("%d\n", ptr->num);
		ptr = ptr->next;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	initiate_a(argc, argv, &a);
	sort_stack(&a, &b);
	retrieve_stack(a);
	free_stack(&a, 0);
	return (0);
}
