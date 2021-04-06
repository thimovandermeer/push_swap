/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 10:49:16 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/06 15:45:30 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
* Error checking functions
*/


/*
* This piece of code checks if the input given are actually numbers
*/

int is_all_num(char *arguments)
{
	int i = 0;

	while(i < ft_strlen(arguments))
	{
		if (!ft_isdigit(arguments[i]))
		{
			ft_putstr_fd("Is not a number\n", 1);
			return (1);
		}
		i++;
	}
	return (0);

}

/*
* This piece of code checks if all arguments given are integers
* it also check if the integer given is not smaller than 0
*/

int is_integer(char *arguments)
{
	int i = 0;
	int res;
	
	while(i < ft_strlen(arguments))
	{
		res = ft_atoi(arguments[i]);
		if (res == -1)
		{
			ft_putstr_fd("Number is not an integer\n", 1);
			return 1;
		}
		if (res < 0)
		{
			ft_putstr_fd("Number is smaller than 0 \n", 1);
			return 1;
		}
		i++;
	}
	return 0;
}

/*
* This piece of code contains all input checking functions it return 1
* if there is an error in the input
*/

int check_inputs(int num_args, char **arguments)
{
	int i = 0;
	while(i < num_args)
	{
		if (is_all_num(arguments))
			return 1;
		if (is_integer(arguments))
			return 1;
		i++;
	}
	return 0;
}

/*
* This piece of code saves all inputs to an int array so sorting will
* be easier in the upcoming code parts
*/

int	save_inputs(char **arguments, t_stack *a, t_stack *b)
{
	b->size = a->size;
	a->current_size = -1;
	b->current_size = a->current_size;
	// malloc the array;
	a->stack = malloc(sizeof(int) * a->size);
	b->stack = malloc(sizeof(int) * b->size);
	if(!b->stack || !a->stack)
		return NULL;
	ft_bzero(a->stack, a->size);
	ft_bzero(b->stack, b->size);
	int i = 0;
	int res;
	while(i < a->size)
	{						
		a->stack[i] = ft_atoi(arguments[i]);
		a->current_size++;
		i++;
	}
	return 0;
}

/*
* This piece of code read the stdin and saves all arguments to a list
*/

int execute_instructions()
{
	
}

int is_sorted()
{

}

int	check_error()
{
	
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char *operator;
	while(get_next_line(STDIN_FILENO, operator) == 1)
	{
		if (check_operator(a, b, operator))
		{
			ft_putstr_fd("Illegal instruction", 1);
			exit(1);
		}
	}
}


int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int *array;
	// check your inputs
	if (argc <= 1)
		return 1;
	if(check_inputs(argc, argv))
		ft_putstr_fd("Error during checking inputs", 1);
	// receive your instructions and safe those in approp format
	a.size = argc - 1;
	if(!save_inputs(argv, &a, &b))
		return 1;
	read_instructions(&a, &b);
	// check if list is sorted

	// display sorted or not message

	// error checking 
}


// argument: a stack which is a list of integers

// program waits for instructions from the standard input each argument should be followed by a \n

// execute the instructions on the list

// check if the list is actually sorted after these arguments

// display OK or KO depending on being sorted or not

// in case of errors display error on standard error
