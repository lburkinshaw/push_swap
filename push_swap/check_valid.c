/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:06:25 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/09 10:41:07 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_repeat(char *current, char *next[], int i)
{
	int j;
	int k;
	int rep;
	
	j = 0;
	k = 0;
	if (current[0] == '+')
		i++;
	while (next[j])
	{
		rep = 1;
		while (current[i] || next[j][k])
		{
			if (next[j][0] == '+')
				k++;
			if (current[i++] != next[j][k++])
			{
				rep = 0;
				break ;
			}
		}
		if (rep == 1)
			return (1);
		j++;
	}
	return (0);
}

int check_digit(char *nums)
{
	int i;

	i = 0;
	if (nums[0] == '-' || nums[0] == '+')
		i++;
	while (nums[i])
		{
			if (nums[i] < 48 || nums[i] > 57)
				return (1);
			i++;
		}
	return (0);
}

int	check_valid(char *nums[])
{
	int i;
	int j;
	
	i = 0;
	while (nums[i])
	{
		j = 0;
		if (nums[i + 1])
		{
			if (check_repeat(nums[i], &nums[i+1], 0) == 1)
				return (1);
		}
		j = 0;
		if (check_digit(nums[i]))
			return (1);
		j = ft_strlen(nums[i]);
		if (j > 11)
			return (1);
		if (ft_atol(nums[i]) < -2147483648 || ft_atol(nums[i]) > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

/*Need to create/split into:
-->
--> a check digit function that also handles the cases of '+' and '-', 
and gives error when '++' or '--' and also if '+6 6'
--> function to check for overflow.
--> function to check for repeat numbers after atol??*/