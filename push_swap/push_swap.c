/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:31 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/12 13:59:58 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Make work for 3 numbers:
./push_swap 2 5 1
./push_swap "2 5 1"

Steps:
- Create stack, -ok
- Add each no. to stack -ok
- Retrieve stack -ok

ERROR CHECKS:
- If repeat, don't put on list (print error or just omit??)
- If more than 11 characters
- check if outside max/min int
--> print error message or initiate stackk


-- rotate stack a
-- swap stack a
*/

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node		*stack;

	stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	if (initiate_stack_a(argc, argv, &stack) == 1) //Checks that more than one number
		return (1);
	sort_stack(&stack);
	//else if more than 3 args...
	//stack B: only reassign nodes from stack a. No need to malloc new nodes.
	retrieve_stack(stack);
	free_stack(&stack, 0);
	return (0);
}
