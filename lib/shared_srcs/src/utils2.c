/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 14:41:29 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 14:42:02 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	is_sorted(t_stack *a)
{
	size_t	i;

	if (a->size != a->current_size)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
