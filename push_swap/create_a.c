/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:19:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:49:45 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	append_num(int nb, t_node **stack)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));//creates node to store nb as num value.
	if (!new_node)
	{
		free_stack(stack);
		return (1);
	}
	new_node->next = NULL;//sets next prt to NULL as end of stack.
	new_node->num = nb;//stores nb
	if (*stack == NULL)//if no other nodes in stack, sets stack to point to new_node.
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else//if other nodes already, finds last node in stack and appends new node to end.
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);//returns 0 on success.
}

static void	add_to_stack(char **arguments, t_node **stack, int split_flag)
{
	int	i;
	int	nb;

	i = 0;
	while (arguments[i])//iterates through arguments array until end.
	{
		nb = ft_atoi(arguments[i]);//uses atoi to convert (already checked validity) and store each arg string as int nb.
		if (append_num(nb, stack) == 1)//appends nb as node at end of stack A. Checks function is sucessful, if not frees and exits.
		{
			free_stack(stack);
			error_n_exit(arguments, split_flag);
		}
		i++;
	}
}

void	create_a(int ac, char *av[], t_node **stack)
{
	char	**arguments;//create new array of strings for easier handling of args.
	int		split_flag;//to indicate that split has been performed and needs to be freed.

	split_flag = 0;
	if (ac == 2)//if 2 args, we need to split string into array.
	{
		arguments = ft_split(av[1], ' ');
		if (!arguments)
			error_n_exit(arguments, 1);
		split_flag = 1;
	}
	else
		arguments = av + 1;//otherwise, set arguments to point to 1st value.
	if (arguments[1] == NULL)//checks that more than one value to sort.
		error_n_exit(arguments, split_flag);
	check_valid(arguments, split_flag);//checks for empty array, invalid characters & dups. If invalid, frees and exits.
	add_to_stack(arguments, stack, split_flag);//adds to stack only if valid.
	if (split_flag)//if split has been used, free here as no longer needed after added to stack.
		free_split(arguments);
}
