/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:06:12 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/15 12:34:23 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

# define GO_UP 0
# define GO_DOWN 1

typedef struct s_stack
{
	size_t 	size;
	size_t 	current_size;
	int		*stack;
}				t_stack;

/*
*  Check Operator functions
*/

int	check_swap_operator(const char *operator, t_stack *a, t_stack *b);
int check_push_operator(const char *operator, t_stack *a, t_stack *b);
int	check_rotate_operator(const char *operator, t_stack *a, t_stack *b);
int check_reverse_operator(const char *operator, t_stack *a, t_stack *b);
int check_operator(t_stack *a, t_stack *b, const char *operator);

/*
*  Operator functions
*/

void	swap_elems(int *old_top, int *new_top);
void	swap_operator(t_stack *stack);
void	push_operator(t_stack *giver, t_stack *receiver);
void	rotate_operator(t_stack *stack);
void	reverse_rotate_operator(t_stack *stack);

/*
*  Checker functions
*/

int		check_inputs(int num_args, char **arguments);
int		save_inputs(char **arguments, t_stack *a, t_stack *b);
void	read_instructions(t_stack *a, t_stack *b);
void	clean_stacks(int **a, int **b);

/*
*  Util functions
*/

void	print_stack(t_stack *a);
int		is_all_num(char *arguments);
int		is_integer(char *arguments);
int		is_sorted(t_stack *a);

/*
*  push_swap functions
*/

int		pos_biggest_number(int *array, int size);
int		pos_smallest_number(int *array, int size);
void	solve_three(t_stack *a);
void	solve_five();
void	solve_hundred();
void	solve_big_stack();
void	solve(t_stack *a, t_stack *b);

/*
*  solve hundred functions
*/

int 	find_median(t_stack *a);
void	sort_array(int *array, int len);
void	push_median(t_stack *a, t_stack *b, int median, int split);
int		find_biggest_smallest(t_stack *b, t_stack *a);