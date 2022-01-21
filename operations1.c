/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:54:59 by mclam             #+#    #+#             */
/*   Updated: 2021/12/09 21:54:59 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *var)
{
	t_stack	*tmp;

	if (var->a != NULL && var->a->next != NULL)
	{
		tmp = var->a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = var->a;
		var->a = var->a->next;
		tmp->next->next = NULL;
	}
	var->counter++;
	if (var->operation == SORTING)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_var *var)
{
	t_stack	*tmp;

	if (var->b != NULL && var->b->next != NULL)
	{
		tmp = var->b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = var->b;
		var->b = var->b->next;
		tmp->next->next = NULL;
	}
	var->counter++;
	if (var->operation == SORTING)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_var *var)
{
	ra(var);
	rb(var);
	var->counter++;
	if (var->operation == SORTING)
		write(STDOUT_FILENO, "rr\n", 3);
}
