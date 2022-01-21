/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:11:19 by mclam             #+#    #+#             */
/*   Updated: 2022/01/19 16:11:19 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	special6_sorting_a(t_var *var, t_sorting mode)
{
	if (var->a != NULL && var->a->next != NULL)
	{
		while (is_sorted(var->a, mode) == FALSE)
		{
			if (mode == ASCNDNG && var->a->index > var->a->next->index)
				sa(var);
			else if (mode == DSCNDNG && var->a->index < var->a->next->index)
				sa(var);
			if (is_sorted(var->a, mode) == TRUE)
				return (var->counter);
			rra(var);
		}
	}
	return (var->counter);
}

int	special6_sorting_b(t_var *var, t_sorting mode)
{
	if (var->b != NULL && var->b->next != NULL)
	{
		while (is_sorted(var->b, mode) == FALSE)
		{
			if (mode == ASCNDNG && var->b->index > var->b->next->index)
				sb(var);
			else if (mode == DSCNDNG && var->b->index < var->b->next->index)
				sb(var);
			if (is_sorted(var->b, mode) == TRUE)
				return (var->counter);
			rrb(var);
		}
	}
	return (var->counter);
}

void	find_index_put_to_stackb(t_var *var, size_t *a_size, size_t index)
{
	size_t			i;
	t_stack			*tmp;

	i = 0;
	tmp = var->a;
	while (tmp != NULL)
	{
		if (tmp->index == index)
		{
			if (i < *a_size / 2)
				while (i--)
					ra(var);
			else
			{
				i = *a_size - i;
				while (i--)
					rra(var);
			}
			pb(var);
			(*a_size)--;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
}

int	stackb_fill_sorting(t_var *var, size_t s_size, t_sorting mode)
{
	size_t	a_size;
	size_t	desired_index;
	
	a_size = s_size;
	desired_index = 0;
	if (mode == DSCNDNG)
		desired_index = s_size - 1;
	while (desired_index < s_size)
	{
		find_index_put_to_stackb(var, &a_size, desired_index);
		if (mode == ASCNDNG)
			desired_index++;
		else if (mode == DSCNDNG)
			desired_index--;
	}
	while (s_size--)
		pa(var);
	return (var->counter);
}
