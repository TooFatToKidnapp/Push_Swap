/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:11:59 by aabdou            #+#    #+#             */
/*   Updated: 2022/01/15 18:13:59 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sa_or_sb(s_array *array, int type, char stack)
{
	int	temp;

	if (type && stack == 'a')
		write(1, "sa\n", 3);
	else if (type && stack == 'b')
		write(1 ,"sb\n", 3);
	if (array->used_size > 1)
	{
		temp = array->array[0];
		array->array[0] = array->array[1];
		array->array[1] = temp;
	}
}

void	ft_sa_and_sb(s_stacks *stacks, int type)
{
	if (type)
		write(1,"ss\n", 3);
	ft_sa_or_sb(&stacks->stack_a, OFF, 'a');
	ft_sa_or_sb(&stacks->stack_b, OFF, 'b');
}
