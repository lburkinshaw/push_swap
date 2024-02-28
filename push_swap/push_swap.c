/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:11:47 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/27 13:49:53 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retrieve_stack(t_node *stack)//DELETE BEFORE SUBMIT
{
	t_node	*ptr;

	if (stack == NULL)
	{
		write(1, "Error", 5);
		return ;
	}
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

	/*argc = 4;
	argv[1] = "5";
	argv[2] = "6";
	argv[3] = "2";
	argv[4] = "3";
	argv[5] = NULL;*/
//above lines 37-42 can be used for debugger. ALternatively launch.json file can specify.

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		error_n_exit(argv, 0);
	create_a(argc, argv, &a);
	sort_stack(&a, &b);
	//retrieve_stack(a);
	free_stack(&a);
	return (0);
}
