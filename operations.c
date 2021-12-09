/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:46:08 by mclam             #+#    #+#             */
/*   Updated: 2021/12/09 18:46:08 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *var)
{
	t_stack	*tmp;
	
	if (var->a != NULL && var->a->next != NULL)
	{
		tmp = var->a;
		var->a = var->a->next;
		tmp->next = var->a->next;
		var->a->next = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_var *var)
{
	t_stack	*tmp;
	
	if (var->b != NULL && var->b->next != NULL)
	{
		tmp = var->b;
		var->b = var->b->next;
		tmp->next = var->b->next;
		var->b->next = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_var *var)
{
	sa(var);
	sb(var);
	write(1, "ss\n", 3);
}

void	pa(t_var *var)
{
	t_stack	*tmp;
	
	if (var->b != NULL)
	{
		tmp = var->b;
		var->b = var->b->next;
		tmp->next = var->a;
		var->a = tmp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_var *var)
{
	t_stack	*tmp;
	
	if (var->a != NULL)
	{
		tmp = var->a;
		var->a = var->a->next;
		tmp->next = var->b;
		var->b = tmp;
	}
	write(1, "pb\n", 3);
}
