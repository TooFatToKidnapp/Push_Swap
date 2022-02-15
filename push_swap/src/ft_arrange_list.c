/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:50:09 by aabdou            #+#    #+#             */
/*   Updated: 2022/01/19 19:50:11 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(int *left, int *right) // swap the first nb with the 2nd one
{
	int	tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

int	*ft_save_list(s_array *stack_a) // store all the numbers from stack a to a new array 
{
	int	i;
	int	*stored_list;

	i = 0;
	stored_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		stored_list[i] = stack_a->array[i];
		i++;
	}
	return (stored_list);
}

int	*ft_sort_array(s_array *stack_a) // sort the numbers in the new stack (bubble sort)
{
	int	i;
	int	j;
	int	smallest_index;
	int	*sorted_list;

	i = 0;
	sorted_list = ft_save_list(stack_a);
	while (i < stack_a->size - 1)
	{
		smallest_index = i;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sorted_list[j] < sorted_list[smallest_index])
				smallest_index = j;
			j++;
		}
		ft_swap(&sorted_list[smallest_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

void	ft_arrange_rest(s_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_check_sorted(&stacks->stack_a))
			ft_sa_or_sb(&stacks->stack_a, ON, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		ft_arrange_three_numbers(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_arrange_five_numbers(stacks);
	if (stacks->stack_a.used_size > 5)
		ft_arrange_rest_of_numbers(stacks, stacks->stack_a.used_size);
}

void 	ft_arrange_more_then_handred(s_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_check_sorted(&stacks->stack_a))
			ft_sa_or_sb(&stacks->stack_a, ON, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		ft_arrange_three_numbers(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_arrange_five_numbers(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		ft_arrange_rest_of_numbers(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		ft_arrange_one_handred(stacks);
}