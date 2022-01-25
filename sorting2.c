/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:13:03 by mclam             #+#    #+#             */
/*   Updated: 2022/01/21 21:13:03 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		markup_sorting_i(t_var *var, size_t s_size, t_sort mode)
{
	size_t	i;

	markup_counter_i(var->a, s_size, mode);
	choose_markup_head_i(var, mode);
	markup_i(var, s_size, mode);
	i = 0;
	while (++i <= s_size)
	{
		if (var->a->stack_a == TRUE)
			ra(var);
		else
			pb(var);
	}
	return (var->counter);
}

void	markup_counter_i(t_stack *head, size_t s_size, t_sort mode)
{
	t_stack	*el;
	t_stack	*tmp;
	size_t	i;
	
	el = head;
	while (el != NULL)
	{
		tmp = fiv(el->next != NULL, el->next, head);
		i = 0;
		while (++i < s_size)
		{
			if (mode == ASCNDNG && tmp->index - el->index == 1 + el->markup_i)
				el->markup_i++;
			if (mode == DSCNDNG && el->index - tmp->index == 1 + el->markup_i)
				el->markup_i++;
			tmp = fiv(tmp->next != NULL, tmp->next, head);
		}
		el = el->next;
	}
}

void choose_markup_head_i(t_var *var, t_sort mode)
{
	t_stack	*tmp;

	tmp = var->a;
	while (tmp != NULL)
	{
		if (tmp->markup_i > var->markup_i[1])
		{
			var->markup_i[0] = tmp->index;
			var->markup_i[1] = tmp->markup_i;
		}
		else if (tmp->markup_i == var->markup_i[1] && tmp->markup_i != 0 && \
				 mode == ASCNDNG && tmp->index < var->markup_i[0])
			{
				var->markup_i[0] = tmp->index;
				var->markup_i[1] = tmp->markup_i;
			}
		else if (tmp->markup_i == var->markup_i[1] && tmp->markup_i != 0 && \
				 mode == DSCNDNG && tmp->index > var->markup_i[0])
			{
				var->markup_i[0] = tmp->index;
				var->markup_i[1] = tmp->markup_i;
			}
		tmp = tmp->next;
	}
}
