/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 14:52:06 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/26 15:15:06 by thvan-de      ########   odam.nl         */
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
	int	i;
	int	smallest_number;

	i = len - 1;
	smallest_number = i;
	while (i)
	{
		if (array[i] <= smallest_number)
			smallest_number = array[i];
		i--;
	}
	return (smallest_number);
}
