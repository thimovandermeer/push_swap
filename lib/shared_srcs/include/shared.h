/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 08:40:48 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/28 10:33:17 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# define GO_UP 0
# define GO_DOWN 1
# include <unistd.h>
# include <stdlib.h>
# include "/Users/thimovandermeer/Desktop/Codam projecten/push_swap/lib/libft/libft.h"
typedef struct s_stack
{
	size_t	size;
	size_t	current_size;
	int		*stack;
}				t_stack;

typedef struct s_steps
{
	int		big_up;
	int		small_up;
	int		big_down;
	int		small_down;
}				t_steps;

/*
*  Util functions
*/

void	print_stack(t_stack *a);
int		is_all_num(char *arguments);
int		is_integer(char *arguments);
int		is_sorted(t_stack *a);
int		save_inputs(char **arguments, t_stack *a, t_stack *b);
int		check_inputs(int num_args, char **arguments);
void	print_array(int *array, int len);
/*
*  Operator functions
*/

void	swap_elems(int *old_top, int *new_top);
void	swap_operator(t_stack *stack);
void	push_operator(t_stack *giver, t_stack *receiver);
void	rotate_operator(t_stack *stack);
void	reverse_rotate_operator(t_stack *stack);

#endif 