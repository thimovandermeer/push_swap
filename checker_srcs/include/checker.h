/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: thvan-de <thvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/22 08:22:33 by thvan-de      #+#    #+#                 */
/*   Updated: 2021/04/29 15:41:17 by thvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../lib/shared_srcs/include/shared.h"
# include <stdio.h>
/*
*  Check Operator functions
*/

int		check_swap_operator(const char *oper, t_stack *a, t_stack *b);
int		check_push_operator(const char *operators, t_stack *a, t_stack *b);
int		check_rotate_operator(const char *operators, t_stack *a, t_stack *b);
int		check_reverse_operator(const char *operators, t_stack *a, t_stack *b);
int		check_operator(t_stack *a, t_stack *b, const char *operators);

/*
*  Checker functions
*/

void	read_instructions(t_stack *a, t_stack *b);
void	clean_stacks(int **a, int **b);
int		main(int argc, char **argv);
#endif