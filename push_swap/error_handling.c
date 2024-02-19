/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:02:37 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/19 11:59:49 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_n_exit(void)
{
	ft_printf("Error\n");
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

void	free_stack(t_node **stack, int error) //check this
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
	if (error)
		error_n_exit();
}
