/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:30:58 by lburkins          #+#    #+#             */
/*   Updated: 2024/03/06 13:03:37 by lburkins         ###   ########.fr       */
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
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
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
	while (*current_ptr && current_ptr[1])
	{
		nxt_ptr = current_ptr + 1;
		while (*nxt_ptr)
		{
			if (ft_atol(*current_ptr) == ft_atol(*nxt_ptr))
				return (1);
			nxt_ptr++;
		}
		current_ptr++;
	}
	return (0);
}

void	check_valid(char **args, int split_flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (args[i])
	{
		if (check_empty(args[i]))
			error_n_exit(args, split_flag);
		if (check_digit(args[i]))
			error_n_exit(args, split_flag);
		len = ft_strlen(args[i]);
		if (len > 11)
			error_n_exit(args, split_flag);
		if (ft_atol(args[i]) < INT_MIN || ft_atol(args[i]) > INT_MAX)
			error_n_exit(args, split_flag);
		i++;
	}
	if (check_dups(args))
		error_n_exit(args, split_flag);
}
