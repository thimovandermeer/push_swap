/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 10:04:39 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/05/03 11:26:48 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	check_duplicate(int *array, int len, int number)
{
	while (len)
	{
		len--;
		if (array[len] == number)
			return (1);
	}
	return (0);
}

int	save_inputs(char **arguments, t_stack *a, t_stack *b)
{
	size_t	i;

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
	while (i)
	{
		a->stack[a->current_size] = ft_atoi(arguments[i]);
		if (check_duplicate(a->stack, a->current_size,
				a->stack[a->current_size]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		a->current_size++;
		i--;
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

int	is_all_num(char *arguments)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(arguments))
	{
		if (!ft_isdigit(arguments[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	is_integer(char *arguments)
{
	size_t	i;
	int		res;

	i = 0;
	while (i < ft_strlen(arguments))
	{
		res = ft_atoi(arguments);
		if (res == -1)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		if (res < 0)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		i++;
	}
	return (0);
}
