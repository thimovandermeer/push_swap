/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 10:49:16 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/07 12:29:26 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


int is_integer(char *arguments)
{
	int i = 0;
	int res;
	
	while(i < ft_strlen(arguments))
	{
		res = ft_atoi(arguments);
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

int check_inputs(int num_args, char **arguments)
{
	int i = 1;
	while(i < num_args)
	{
		if (is_all_num(arguments[i]))
			return 1;
		if (is_integer(arguments[i]))
			return 1;
		i++;
	}
	return 0;
}

int	save_inputs(char **arguments, t_stack *a, t_stack *b)
{
	int i = 1;
	int res;
	int j; 
	b->size = a->size;
	a->current_size = 0;
	b->current_size = a->current_size;
	a->stack = malloc(sizeof(int) * a->size);
	b->stack = malloc(sizeof(int) * b->size);
	if(!b->stack || !a->stack)
		return -1;
	ft_bzero(a->stack, a->size);
	ft_bzero(b->stack, b->size);
	j = 0;
	while(arguments[i])
	{
		a->stack[j] = ft_atoi(arguments[i]);
		a->current_size++;
		i++;
		j++;
	}
	return 0;
}

int	is_sorted(t_stack *a)
{
	int	i;

	if (a->size != a->current_size)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}


void	read_instructions(t_stack *a, t_stack *b)
{
	char *operator;
	
	while(get_next_line(STDIN_FILENO, &operator))
	{
		if (!ft_strcmp(operator, "STOP"))
			break ;
		if (!check_operator(a, b, operator))
		{
			ft_putstr_fd("Illegal instruction", 1);
			exit(1);
		}
		print_stack(a);
		print_stack(b);
	}
}

void clean_stacks(int **a, int **b)
{
	free(*a);
	free(*b);
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int *array;
	if (argc <= 1)
		return 1;
	if(check_inputs(argc, argv))
	{
		ft_putstr_fd("Error during checking inputs", 1);
		exit(1);
	}
	a.size = argc;
	if(save_inputs(argv, &a, &b) == -1)
		return 1;
	read_instructions(&a, &b);
	a.size = argc - 1;
	int ret = is_sorted(&a);
	if (ret == 1)
		ft_putstr_fd("OK\n", 1 );
	else
		ft_putstr_fd("KO\n", 1 );
	clean_stacks(&a.stack, &b.stack);
}
