/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 09:04:52 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// zo weg gooien
void	print_array(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%i = %i\n", i, array[i]);
		i++;
	}
}

void 	find_quarters(t_stack *a, int *quarters)
{
	int	quarter_size;
	int	array[a->current_size];
	int num_quarters;
	int	i;

	num_quarters = 5; // zometeen variabel
	quarter_size = a->current_size / (num_quarters - 1);

	i = 0;
	ft_bzero(array, a->current_size);
	while (i < a->current_size)
	{
		array[i] = a->stack[i];
		i++;
	}
	sort_array(array, a->current_size);
	// print_array(array , a->current_size);
	i = 0;
	while (i < (num_quarters - 1))
	{
		quarters[i] = array[quarter_size * i];
		// printf("[%i] quarter = %i\n",i , quarters[i]);
		i++;
	}
	quarters[i] = array[a->current_size - 1];
	// printf("[%i] quarter = %i\n",i , quarters[i]);
}
