/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test_push_swap.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 10:55:03 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 09:04:10 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_three()
{
	t_stack a;
	t_stack b;
	int test[3] = {2, 3, 1};
	a.size = 3;
	a.current_size = 0;
	a.stack = malloc(sizeof(int) * a.size);
	b.size = 5;
	b.current_size = 0;
	b.stack = malloc(sizeof(int) * b.size);
	int i = 0;
	while(i < a.size)
	{
		a.stack[i] = test[i];
		i++;
		a.current_size++;
	}
	print_stack(&a);
	solve_three(&a, &b);
	print_stack(&a);
}

void	test_five()
{

}

void	test_hundred()
{

}

void 	test_big_stack()
{

}

int main()
{
	test_three();
}