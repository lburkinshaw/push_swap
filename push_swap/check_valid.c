/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:30:58 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/04 13:49:32 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty(char *str)
{
	if (*str == '\0')
		return (1);
	return (0);
}

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (str[i] < 48 || str[i] > 57)//filters out cases such as "3 2 -"
			return (1);
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)//if not digit, returns 1.
			return (1);
		i++;
	}
	return (0);
}

static int	check_dups(char **array)
{
	char	**current_ptr;
	char	**nxt_ptr;

	current_ptr = array;
	nxt_ptr = NULL;
	while (*current_ptr && current_ptr[1])//while there is a subsequent string to compare with.
	{
		nxt_ptr = current_ptr + 1;
		while (*nxt_ptr)//runs through all subsequent strings in array and compares to current.
		{
			if (ft_atol(*current_ptr) == ft_atol(*nxt_ptr))
				return (1);
			nxt_ptr++;
		}
		current_ptr++;//moves current ptr to next string.
	}
	return (0);
}

void	check_valid(char **args, int split_flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (args[i])//all invalid outcomes error and exit. otherwise continue back to create_a.
	{
		if (check_empty(args[i]))//if check_empty returns 1, indicates error.
			error_n_exit(args, split_flag);
		if (check_digit(args[i]))//if check_digit returns 1, indicates error.
			error_n_exit(args, split_flag);
		len = ft_strlen(args[i]);
		if (len > 11)//pre-filters for strings longer than no. chars in max & min int.
			error_n_exit(args, split_flag);
		if (ft_atol(args[i]) < INT_MIN || ft_atol(args[i]) > INT_MAX)//use atol to check within limits of integer. 
			error_n_exit(args, split_flag);
		i++;
	}
	if (check_dups(args))//check for duplicate values. If check_dups returns 1, indicates error.
		error_n_exit(args, split_flag);
}
