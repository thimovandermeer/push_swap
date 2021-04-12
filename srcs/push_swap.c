/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 10:09:31 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 09:05:19 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		pos_biggest_number(int *array, int size)
{
	int i;
	int biggest_number_pos;
	biggest_number_pos = 0;
	i = 0;
	// check even of de size ook echt correspondeert
	while(i < size)
	{
		if(array[biggest_number_pos] < array[i])
			biggest_number_pos = i;
		i++;
	}
	return (biggest_number_pos);
}

int		pos_smallest_number(int *array, int size)
{
	int i;
	int smallest_number_pos;
	smallest_number_pos = 0;
	i = 0;
	// check even of de size ook echt correspondeert
	printf("smallest before loop = %i\n", smallest_number_pos);
	while(i < size)
	{
		if(array[smallest_number_pos] > array[i])
			smallest_number_pos = i;
		i++;
	}
	return (smallest_number_pos);
}

void	solve_three(t_stack *a, t_stack *b)
{
	// need to find out which is the biggest
	int biggest = pos_biggest_number(a->stack, a->current_size);
	int smallest = pos_smallest_number(a->stack, a->current_size);
	// compare the current with the biggest multiple times
	if(biggest == 1 && smallest == 0)
	{
		swap_operator(a);
		rotate_operator(a);
	}
	else if (biggest == 1 && smallest == 2)
		reverse_rotate_operator(a);
	else if (biggest ==  0 && smallest == 1)
		rotate_operator(a);
	else if (smallest == 2 && biggest == 0)
	{
		swap_operator(a);
		reverse_rotate_operator(a);
	}
	else
		swap_operator(a);
}

void	solve_five()
{
	
}

void	solve_hundred()
{

}

void	solve_big_stack()
{
	
}

void	solve(t_stack *a, t_stack *b)
{
	if(!is_sorted(a))
	{
		if (a->size <= 3)
			solve_three(a, b);
		if (a->size <= 5)
			solve_five();
		if (a->size <= 100)
			solve_hundred();
		else
			solve_big_stack();
	}	
}

// int main(int argc, char **argv)
// {
// 	// check inputs 
// 	t_stack	a;
// 	t_stack	b;
// 	int		ret;
// 	int		*array;

// 	if (argc <= 1)
// 		return (1);
// 	// still need to check for duplicates
// 	if (check_inputs(argc, argv))
// 	{
// 		ft_putstr_fd("Error during checking inputs", 1);
// 		exit(1);
// 	}
// 	// save inputs
// 	a.size = argc;
// 	if (save_inputs(argv, &a, &b) == -1)
// 		return (1);
// 	// check if sorted
// 	solve(&a, &b);
// }