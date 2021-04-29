/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:52:06 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 10:29:25 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int	smallest_num(int *array, int len)
{
	int i = 0;
	int smallest_num = 100000;
	while(i < len)
	{
		if (array[i] < smallest_num)
			smallest_num = array[i];
		i++;
	}
	return smallest_num;
}
