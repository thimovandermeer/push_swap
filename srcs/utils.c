/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 10:04:39 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/12 13:35:06 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	save_inputs(char **arguments, t_stack *a, t_stack *b)
{
	int	i;
	int	res;
	int	j;

	i = a->size;
	b->size = a->size;
	a->current_size = 0;
	b->current_size = a->current_size;
	a->stack = malloc(sizeof(int) * a->size);
	b->stack = malloc(sizeof(int) * b->size);
	if (!b->stack || !a->stack)
		return (-1);
	ft_bzero(a->stack, a->size);
	ft_bzero(b->stack, b->size);
	j = 0;
	while (i)
	{
		a->stack[j] = ft_atoi(arguments[i]);
		a->current_size++;
		i--;
		j++;
	}
	return (0);
}

int	check_inputs(int num_args, char **arguments)
{
	int	i;

	i = 1;
	while (i < num_args)
	{
		if (is_all_num(arguments[i]))
			return (1);
		if (is_integer(arguments[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->current_size)
	{
		printf("%i = %i\n", i, a->stack[i]);
		i++;
	}
	printf("Full stack has been printed\n");
}

int	is_all_num(char *arguments)
{
	int	i;

	i = 0;
	while (i < ft_strlen(arguments))
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

int	is_integer(char *arguments)
{
	int	i;
	int	res;

	i = 0;
	while (i < ft_strlen(arguments))
	{
		res = ft_atoi(arguments);
		if (res == -1)
		{
			ft_putstr_fd("Number is not an integer\n", 1);
			return (1);
		}
		if (res < 0)
		{
			ft_putstr_fd("Number is smaller than 0 \n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;

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
