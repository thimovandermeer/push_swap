/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_operators.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:40:48 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/07/09 13:41:07 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_srcs/include/checker.h"

/*
* 	This function checks which swap operation is being asked, it executes the right operation afterwards.
*	The swap operation can be called either on the A stack or the B stack, thats why both are being taken in. 
*/

int	check_swap_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "sa"))
	{
		swap_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "sb"))
	{
		swap_operator(b);
		return (1);
	}	
	if (!ft_strcmp(operator, "ss"))
	{
		swap_operator(b);
		swap_operator(a);
		return (1);
	}
	return (0);
}

/*
* 	This function checks which push operation is being asked, it executes the right operation afterwards.
*	The push operation can be called either on the A stack or the B stack, thats why both are being taken in.
*/


int	check_push_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "pa"))
	{
		push_operator(b, a);
		return (1);
	}
	if (!ft_strcmp(operator, "pb"))
	{
		push_operator(a, b);
		return (1);
	}
	return (0);
}

/*
* 	This function checks which rotate operator is being asked, it executes the right operation afterwards.
*	The rotate operation can be called either on the A stack or the B stack, or the two at the same time
*	thats why both are being taken in.
*/


int	check_rotate_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "ra"))
	{
		rotate_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "rb"))
	{
		rotate_operator(b);
		return (1);
	}
	if (!ft_strcmp(operator, "rr"))
	{
		rotate_operator(a);
		rotate_operator(b);
		return (1);
	}
	return (0);
}

/*
* 	This function checks which reverse rotate operator is being asked, it executes the right operation afterwards.
*	The rotate operation can be called either on the A stack or the B stack, or the two at the same time
*	thats why both are being taken in.
*/


int	check_reverse_operator(const char *operator, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operator, "rra"))
	{
		reverse_rotate_operator(a);
		return (1);
	}
	if (!ft_strcmp(operator, "rrb"))
	{
		reverse_rotate_operator(b);
		return (1);
	}
	if (!ft_strcmp(operator, "rrr"))
	{
		reverse_rotate_operator(a);
		reverse_rotate_operator(b);
		return (1);
	}
	return (0);
}

/*
* 	This function combines all above functions, it checks the operator and executes it
*	if 0 is being returned it means that no operator has been called and so there is an error in the operator
*/


int	check_operator(t_stack *a, t_stack *b, const char *operator)
{
	if (check_swap_operator(operator, a, b))
		return (1);
	if (check_push_operator(operator, a, b))
		return (1);
	if (check_rotate_operator(operator, a, b))
		return (1);
	if (check_reverse_operator(operator, a, b))
		return (1);
	return (0);
}
