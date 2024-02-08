/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:18:31 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/08 10:32:36 by lburkins         ###   ########.fr       */
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
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	add_to_stack(long int nb, t_Node **stack)
{
	t_Node	*new_node;
	t_Node	*last_ptr;

	new_node = malloc(sizeof(t_Node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->num = nb;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_ptr = find_last_node(*stack);
	last_ptr->next = new_node;
}

void	retrieve_stack(t_Node *stack)
{
	if (stack == NULL)
		return ;
	while (stack)
	{
		ft_putnbr_fd(stack->num, 1);
		stack = stack->next;
		ft_putchar_fd('\n', 1);
	}
}

t_Node	*find_last_node(t_Node *lst)
{
	t_Node	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
int check_repeat(char *current, char *next[])
{
	int i;
	int j;
	int rep;
	
	i = 0;
	j = 0;
	while (next[j])
	{
		rep = 1;
		while (current[i] || next[j][i])
		{
			if (current[i] != next[j][i])
			{
				rep = 0;
				break ;
			}
			i++;
		}
		if (rep == 1)
			return (1);
		j++;
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
		//1. check for repeat numbers
		if (nums[i + 1])
		{	
			if (check_repeat(nums[i], &nums[i+1]) == 1)
				return (1);
		}
		//2. check for only digits
		j = 0;
		while (nums[i][j])
		{
			if ((nums[i][j] < 48 || nums[i][j] > 57) && nums[i][0] != '-')
				return (1);
			j++;
		}
		//3. check if more than 11 chars
		/*if (j > 11)//check this!
			return (-1);*/
		//4. check if outside max/min int
		if (ft_atol(nums[i]) < -2147483648 || ft_atol(nums[i]) > 2147483647)
			return (1);
		i++;
	}
		return (0);
}

int	main(int argc, char *argv[])
{
	int			i;
	long int	nb;
	t_Node		*stack;

	stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2nd argument is `0`
		return (1);
	else if (argc == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		if (check_valid(&argv[i]) == 1)
		{
			ft_putendl_fd("error", 2);
			return(0);
		}
		while (argv[i]) //add to stack
		{
			nb = ft_atol(argv[i]); //convert str to long int.
			add_to_stack(nb, &stack);
			i++;
		}
	}
	else
	{
		i = 1;
		if (check_valid(&argv[i]) == 1)
		{
			ft_putendl_fd("error", 2);
			return(0);
		}
		while (i < argc) //add to stack
		{
			nb = ft_atol(argv[i]); //convert str to long int -- need to create own function.
			add_to_stack(nb, &stack);//return number of items in stack?? to use for stack b and sorti ng algorithm choice?
			i++;
		}
	}
	//initiate stack b
	//sort 3
	
	retrieve_stack(stack);
	free(stack);
	return (0);
}