/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:02:37 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 14:06:38 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_n_exit(char **arguments, int split_flag)
{
	if (split_flag)
		free_split(arguments);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = *stack;
	next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
