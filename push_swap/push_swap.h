/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lburkins <lburkins@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:40 by lburkins          #+#    #+#             */
/*   Updated: 2024/02/20 14:46:21 by lburkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct node
{
	int			num;
	struct node	*next;
	struct node	*prev;
}	t_node;

int		main(int argc, char	*argv[]);
void	retrieve_stack(t_node *stack);
void	initiate_a(int ac, char *av[], t_node **stack);
void	add_to_stack(char **arguments, t_node **stack, int split_flag);
int		append_num(int nb, t_node **stack);
void	check_valid(char **args, int split_flag);
int		check_digit(char *str);
int		check_empty(char *str);
//int		check_dups_stack(t_node *stack);
int		check_dups(char **array);
void	sort_stack(t_node **a, t_node **b);
int		check_sorted(t_node *stack);
void	sort_three(t_node **stack);
void	rotate(t_node **stack);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	error_n_exit(char **arguments, int split_flag);
void	rev_rotate(t_node **stack);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	swap(t_node	**stack);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	error_sort(t_node **stack, char **split, int split_flag);
void	free_split(char **array);
void	free_stack(t_node **stack);
t_node	*find_last_node(t_node *lst);
int		count_nodes(t_node *lst);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

#endif