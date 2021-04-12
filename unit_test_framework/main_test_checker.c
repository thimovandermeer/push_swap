/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test_checker.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 14:49:35 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 08:37:05 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/includes/push_swap.h"
#include <stdio.h>
/*
* This file contains all the unit testing logic of my code.
*/

void	print_stack(t_stack *a)
{
	int i = 0;
	while(i < a->current_size)
	{
		printf("%i = %i\n", i, a->stack[i]);
		i++;
	}
	printf("Full stack has been printed\n");
}

t_stack	create_mock_values(int which)
{
	t_stack a;
	if (which == 2)
	{
		
		int test[5] = {1, 4, 5, 6,7};
		a.size = 5;
		a.current_size = 0;
		a.stack = malloc(sizeof(int) * a.size);
		int i = 0;
		while(i < a.size)
		{
			a.stack[i] = test[i];
			i++;
			a.current_size++;
		}
	}
	if (which == 1)
	{
		int test[8] = {1, 4, 5, 6,7,8,9,15};
		a.size = 8;
		a.current_size = 0;
		a.stack = malloc(sizeof(int) * a.size);
		int i = 0;
		while(i < a.size)
		{
			a.stack[i] = test[i];
			i++;
			a.current_size++;
		}
	}
	return a;
}

void 	test_swap_elements()
{
	int old_top = 7;
	int new_top = 6;
	swap_elems(&old_top, &new_top);
	if(old_top != 6)
		printf("swap_elems does not function properly old top value = %i should be %i\n", old_top, 6);
	else
		printf("succesfol swap oldtop = %i and should equal = %i\n", old_top, 6);
}

void	test_swap_operator()
{
	t_stack a;
	int which = 1;
	
	while(which < 3)
	{
		a = create_mock_values(which);
		int old_value = a.stack[a.current_size];
		print_stack(&a);
		swap_operator(&a);
		print_stack(&a);
		which++;
	}
}

void 	test_push_operator()
{
	t_stack a;
	t_stack b;
	int test[5] = {1, 4, 5, 6,7};
	a.size = 5;
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
	printf("Printing stack A\n");
	print_stack(&a);
	printf("Printing stack B\n");
	print_stack(&b);
	push_operator(&a, &b);
	printf("Printing stack A\n");
	print_stack(&a);
	printf("Printing stack B\n");
	print_stack(&b);
}

void	test_rotate_operator()
{
	t_stack a;
	int test[5] = {1, 4, 5, 6,7};
	a.size = 5;
	a.current_size = 0;
	a.stack = malloc(sizeof(int) * a.size);
	int i = 0;
	while(i < a.size)
	{
		a.stack[i] = test[i];
		i++;
		a.current_size++;
	}
	print_stack(&a);
	rotate_operator(&a);
	print_stack(&a);
}

void test_reverse_operator()
{
	t_stack a;
	int test[5] = {1, 4, 5, 6,7};
	a.size = 5;
	a.current_size = 0;
	a.stack = malloc(sizeof(int) * a.size);
	int i = 0;
	while(i < a.size)
	{
		a.stack[i] = test[i];
		i++;
		a.current_size++;
	}
	print_stack(&a);
	reverse_rotate_operator(&a);
	print_stack(&a);
}

void	test_operators()
{
	// test_swap_elements();
	// test_swap_operator();
	// test_push_operator();
	// test_rotate_operator();
	// test_reverse_operator();

	// tests for the game rules
	
	printf("Finished testing operators\n");
	
}

void	test_inputs()
{
	
}

int main()
{
	// test swap elemens
	// test_inputs();
	test_operators();

	
	
}

