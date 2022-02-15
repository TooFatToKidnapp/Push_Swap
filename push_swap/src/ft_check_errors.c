/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:58:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/01/19 19:58:31 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_number(char *number) // check if the given char is a number at a given point 
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicates(s_stacks *stacks, int number)  // checks for duplicate numbers 
{
	int	size;
	int	i;

	i = 0;
	size = stacks->stack_a.used_size;
	if (size == 0)
		return (1);
	while (i < size)
	{
		if (stacks->stack_a.array[i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_sorted(s_array *array) // check if the stack is sorted
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = array->array;
	while (i < array->used_size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_numbers(char *string) // counts numbers :^)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	ft_err_and_free(s_stacks *stacks, char *message, int ret) //prints out ERROR meg and frees the stack's
{
	if (stacks)
	{
		if (stacks->stack_a.array)
			free(stacks->stack_a.array);
		if (stacks->stack_b.array)
			free(stacks->stack_b.array);
	}
	if (message != NULL)
		write(1, "Error\n", 6);
	return (ret);
}