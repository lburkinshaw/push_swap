/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:19:14 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/22 11:16:01 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_num(int nb, t_node **stack)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);//should i print error message?
		return (1);
	}
	new_node->next = NULL;
	new_node->num = nb;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}

void	add_to_stack(char **arguments, t_node **stack, int split_flag)
{
	int	i;
	int	nb;

	i = 0;
	while (arguments[i])
	{
		nb = ft_atoi(arguments[i]);
		if (append_num(nb, stack) == 1)
		{
			free_stack(stack);
			error_n_exit(arguments, split_flag);
		}
		i++;
	}
}

void	create_a(int ac, char *av[], t_node **stack)
{
	char	**arguments;
	int		split_flag;
	int		i;

	arguments = NULL;
	split_flag = 0;
	i = 0;
	if (ac == 2)
	{
		arguments = ft_split(av[1], ' ');
		if (!arguments)
			error_n_exit(arguments, 1);
		split_flag = 1;
	}
	else
		arguments = av + 1;
	if (av[1] == NULL)
		error_n_exit(arguments, split_flag);
	check_valid(arguments, split_flag);
	add_to_stack(arguments, stack, split_flag);
	if (split_flag)
		free_split(arguments);
}