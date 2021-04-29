/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 11:25:52 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/28 14:01:10 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "/Users/thimovandermeer/Desktop/push_swap_compare/lib/shared_srcs/include/shared.h"
# include <stdio.h>
typedef	struct s_quarters
{
	int first_q;
	int second_q;
	int thirth_q;
	int fourth_q;
}				t_quarters;


/*
*  push_swap functions
*/

int		pos_biggest_number(int *array, int size);
int		pos_smallest_number(int *array, int size);
void	solve_three(t_stack *a);
void	solve_five(t_stack *a, t_stack *b);
void	solve_hundred(t_stack *a, t_stack *b);
void	solve_big_stack(void);
void	solve(t_stack *a, t_stack *b);

/*
*  solve hundred functions
*/

void	push_median(t_stack *a, t_stack *b, int median, int split);
void	find_quarters(t_stack *a, int *quarters);
void	move_up(int steps, t_stack *b, t_stack *a, int flag);
void	move_down(int steps, t_stack *b, t_stack *a, int flag);
void	find_biggest_smallest(t_stack *b, t_stack *a, int current_quarter, int *quarters);

/*
*  solve hundred util functions
*/

void	sort_array(int *array, int len);
int		smallest_num(int *array, int len);
void 	fill_steps(t_steps *steps, t_stack *b, int current_quarter, int *quarters);
int		find_up(t_steps *steps, t_stack *b, t_stack *a, int after_rotate);
int		find_down(t_steps *steps, t_stack *b, t_stack *a, int after_rotate);


#endif