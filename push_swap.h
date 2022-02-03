/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:43:31 by mclam             #+#    #+#             */
/*   Updated: 2021/12/08 19:43:31 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBAG_MODE
#  define DEBAG_MODE TRUE
# endif

# ifndef SORTING_MODE
#  define SORTING_MODE ASCNDNG
# endif

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

typedef enum e_sort		t_sort;
typedef struct s_stack	t_stack;
typedef struct s_tree	t_tree;
typedef struct s_var	t_var;
typedef struct s_oper	t_oper;

enum e_sort
{
	TESTING,
	SORTING,
	ASCNDNG,
	DSCNDNG,
};

struct s_var
{
	int		counter;
	size_t	n;
	t_stack	*a;
	t_stack	*b;
	t_tree	*root;
	t_sort	procedure;
	t_oper	*ptrs_array;
};

struct s_stack
{
	int		data;
	size_t	index;
	t_stack	*next;
};

struct s_tree
{
	t_stack	*element;
	t_tree	*left;
	t_tree	*right;
};

struct	s_oper
{
	char	*name;
	void	(*ptr)(t_var *var);
	t_oper	*next;
};

/*
** 		init.c
*/
void	init(t_var *var, int argc, const char **argv);
void	error_exit(void);
/*
** 		indexing_a.c
*/
void	build_tree(t_var *var);
void	indexing_a(t_var *var);
/*
** 		operations.c
*/
void	sa(t_var *var);
void	sb(t_var *var);
void	ss(t_var *var);
void	pa(t_var *var);
void	pb(t_var *var);
/*
** 		operations1.c
*/
void	ra(t_var *var);
void	rb(t_var *var);
void	rr(t_var *var);
/*
** 		operations2.c
*/
void	rra(t_var *var);
void	rrb(t_var *var);
void	rrr(t_var *var);
/*
** 		sorting.c
*/
int		bubble_sorting_a(t_var *var, size_t a_size, t_sort mode);
int		bubble_sorting_b(t_var *var, size_t b_size, t_sort mode);
int		bubble_2stacks_sorting(t_var *var, size_t s_size, t_sort mode);
/*
** 		sorting1.c
*/
int		special6_sorting_a(t_var *var, t_sort mode);
int		special6_sorting_b(t_var *var, t_sort mode);
int		fill_stack_b_sorting(t_var *var, size_t s_size, t_sort mode);
int		radix2_sorting(t_var *var, size_t s_size, t_sort mode);
/*
** 		sorting2.c
*/
int		radix2_sorting_optmzd(t_var *var, size_t s_size, t_sort mode);
/*
** 		utils.c
*/
int		is_sorted(t_stack *s, t_sort mode);
int		push_swap_atoi(const char *str);
int		find_min(int *a, int i);
void	print_stacks(t_var *var);
void	print_info(t_var *var, t_sort mode, int *test);

#endif
