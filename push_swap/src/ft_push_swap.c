/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:38:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/01/16 20:07:03 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_arg_to_string(char **av) // put all the content of av into a string
{
	char *string;
	char *tmp;
	int size;
	int i;

	i = 1;
	size = ft_size_of_av(av);
	string = (char *)malloc(1);
	while (av[i])
	{
		if (!ft_check_arg(av[i]))
			exit(ft_err_and_free(NULL, "Error", 0));
		else
		{
			tmp = ft_strjoin(string, av[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free(tmp);
			i++;
		}
	}
	return (string);
}

s_stacks ft_create_stack(char *str) //stor nb's in stack a 
{
	s_stacks stacks;
	char **numbers;
	long long number;
	int i;

	i = 0;
	numbers = ft_stacks_init(str, &stacks);
	while (numbers[i])
	{
		if (!ft_check_number(numbers[i]))
			exit(ft_err_and_free(&stacks, "Error", 0));
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(ft_err_and_free(&stacks, "Error", 0));
		if (!ft_check_duplicates(&stacks, number))
			exit(ft_err_and_free(&stacks, "Error", 0));
		stacks.stack_a.array[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

char **ft_stacks_init(char *string, s_stacks *stacks) // stor nb's in 2d array
{
	int size;
	char **numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.array = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

int ft_check_arg(char *av) // check if av at a given point is a numbere
{
	int i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int ft_size_of_av(char **av) // get size of av
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (av[i])
		size += ft_strlen(av[i++]) + 1;
	return (size);
}

