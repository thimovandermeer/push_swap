/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_solve.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 14:30:56 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/05/03 11:20:17 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three_part_two(t_stack *a, int biggest, int smallest)
{
	if (biggest == 2 && smallest == 0)
	{
		ft_putstr_fd("sa\n", 1);
		swap_operator(a);
		ft_putstr_fd("rra\n", 1);
		reverse_rotate_operator(a);
	}
	else if (biggest == 2 && smallest == 1)
	{
		rotate_operator(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (smallest == 2 && biggest == 1)
	{
		ft_putstr_fd("sa\n", 1);
		swap_operator(a);
		ft_putstr_fd("ra\n", 1);
		rotate_operator(a);
	}
	else if (biggest == 1 && smallest == 0)
	{
		reverse_rotate_operator(a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	solve_three(t_stack *a)
{
	int	biggest;
	int	smallest;

	biggest = pos_biggest_number(a->stack, a->current_size);
	smallest = pos_smallest_number(a->stack, a->current_size);
	if (biggest == 0 && smallest == 1)
	{
		swap_operator(a);
		ft_putstr_fd("sa\n", 1);
	}
	solve_three_part_two(a, biggest, smallest);
}

void	print_stack(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->current_size)
	{
		printf("%zu = %i\n", i, a->stack[i]);
		i++;
	}
	printf("Full stack has been printed\n");
}

void	solve_five(t_stack *a, t_stack *b)
{
	int biggest;
	int smallest;

	
	while(a->current_size > 3)
	{
		biggest = pos_biggest_number(a->stack, a->current_size);
		smallest = pos_smallest_number(a->stack, a->current_size);
		if (biggest == a->current_size - 1 || smallest == a->current_size - 1)
		{
			ft_putstr_fd("pb\n", 1);
			push_operator(a, b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			rotate_operator(a);
		}
	}
	solve_three(a);
	ft_putstr_fd("pa\n", 1);
	push_operator(b, a);
	if (a->stack[a->current_size - 1] > a->stack[0])
	{
		ft_putstr_fd("ra\n", 1);
		rotate_operator(a);
	}
	ft_putstr_fd("pa\n", 1);
	push_operator(b, a);
	if (a->stack[a->current_size - 1] > a->stack[0])
	{
		ft_putstr_fd("ra\n", 1);
		rotate_operator(a);
	}
	// print_stack(a);
}
