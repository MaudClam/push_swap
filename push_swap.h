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

# include <stdio.h>//FIXME
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack	t_stack;
typedef struct s_tree	t_tree;
typedef struct s_var	t_var;

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

struct s_var
{
	int		n;
	t_stack	*a;
	t_stack	*b;
	t_tree	*root;
};
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
** 		utils.c
*/
void	swap(t_stack **a, t_stack **b);

#endif
