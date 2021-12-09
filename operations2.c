/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:39:07 by mclam             #+#    #+#             */
/*   Updated: 2021/12/09 22:39:07 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_var *var)
{
	t_stack	*tmp;

	if (var->a != NULL && var->a->next != NULL)
	{
		tmp = var->a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = var->a;
		var->a = tmp->next;
		tmp->next = NULL;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_var *var)
{
	t_stack	*tmp;

	if (var->a != NULL && var->a->next != NULL)
	{
		tmp = var->b;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = var->b;
		var->b = tmp->next;
		tmp->next = NULL;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_var *var)
{
	rra(var);
	rrb(var);
	write(1, "rrr\n", 4);
}