/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_hundred.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 08:17:43 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/13 14:50:27 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_array(int *array, int len)
{
	int tmp;
	int	i;

	i = 0;
	tmp = 0;
	while(i < len - 1)
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

void	push_median(t_stack *a, t_stack *b, int median)
{

	int i;

	i = 0;
	while(i < a->size)
	{
		if (a->stack[a->current_size - 1] <= median)
			push_operator(a, b);
		else
			rotate_operator(a);
		i++;
		printf("hang ik in deze ?\n");
	}
	
}

void	print_array(int *array, int len)
{
	int i = 0;
	while(i < len)
	{
		printf("%i = %i\n", i, array[i]);
		i++;
	}
}
// function to find the median
int 	find_median(t_stack *a)
{
	int quarter_len; 
	int array[a->current_size];
	int median;
	int i;

	median = 0;
	quarter_len = a->current_size / 4;
	i = 0;
	ft_bzero(array, a->current_size);
	printf("current_size = %zu\n", a->current_size);
	while(i < a->current_size)
	{
		array[i] = a->stack[i];
		i++;
	}
	sort_array(array, a->current_size);
	median = array[quarter_len * 2];
	return (median);
}



// int		move_smallest(t_stack *tmp, int smallest)
// {
// 	int steps_to_start;
// 	int	steps_to_end;

// 	if(tmp)
// 	{
// 		moves_to_start();
// 		moves_to_end();
// 	}
// 	return 0;
// }

// int		move_biggest()
// {
// 	return 0;
// }

// void	find_moves( t_stack *b, int biggest, int smallest)
// {	
// 	t_stack *tmp;

// 	tmp = b;
// 	move_smallest(tmp, smallest);
// 	move_biggest();
// }

void	move_up(int steps, t_stack *b, t_stack *a)
{
	int i;

	i = 0;
	while(i < steps)
	{
		rotate_operator(b);
		i++;
	}
	push_operator(b,a);
}
void	move_down()
{

}

int		find_biggest_smallest(t_stack *b, t_stack *a)
{
	int biggest;
	int smallest;
	int after_rotate;
	biggest = b->current_size - pos_biggest_number(b->stack, b->current_size);
	smallest = b->current_size - pos_smallest_number(b->stack, b->current_size);
	biggest -= 1;
	smallest -= 1;
	after_rotate = 0;
	if (smallest < biggest)
	{
		move_up(smallest, b, a);
		rotate_operator(a);
	}
	if (biggest < smallest)
	{
		move_up(biggest, b, a);
		after_rotate++;
	}
		
	printf("current_size = %zu\n", b->current_size);
	if (b->current_size == 1)
		push_operator(b, a);
	return after_rotate;
}