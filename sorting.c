/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:33:42 by mclam             #+#    #+#             */
/*   Updated: 2021/12/10 12:33:42 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sorting_a(t_var *var, size_t a_size, t_sort mode)
{
	size_t	i;
	
	if (var->a != NULL && var->a->next != NULL)
	{
		while (is_sorted(var->a, mode) == FALSE)
		{
			i = a_size - 1;
			while (i--)
			{
				if (mode == ASCNDNG && var->a->index > var->a->next->index)
					sa(var);
				else if (mode == DSCNDNG && var->a->index < var->a->next->index)
					sa(var);
				if (is_sorted(var->a, mode) == TRUE)
					return (var->counter);
				ra(var);
			}
			if (is_sorted(var->a, mode) == FALSE)
				ra(var);
		}
	}
	return (var->counter);
}

static int	bubble_sorting_b(t_var *var, size_t b_size, t_sort mode)
{
	size_t	i;
	
	if (var->b != NULL && var->b->next != NULL)
	{
		while (is_sorted(var->b, mode) == FALSE)
		{
			i = b_size - 1;
			while (i--)
			{
				if (mode == ASCNDNG && var->b->index > var->b->next->index)
					sb(var);
				else if (mode == DSCNDNG && var->b->index < var->b->next->index)
					sb(var);
				if (is_sorted(var->b, mode) == TRUE)
					return (var->counter);
				rb(var);
			}
			if (is_sorted(var->b, mode) == FALSE)
				rb(var);
		}
	}
	return (var->counter);
}

static void	bubble_2stacks_sorting_ascndng(t_var *var, size_t s_size)
{
	size_t	i;
	size_t	b_size;

	i = 0;
	b_size = 0;
	while (s_size > 3 && i < s_size && b_size < s_size / 2)
	{
		if (var->a->index < s_size / 2 && ++b_size)
			pb(var);
		else
			ra(var);
		i++;
	}
	if (s_size > 6)
	{
		bubble_sorting_a(var, s_size - b_size, ASCNDNG);
		bubble_sorting_b(var, b_size, DSCNDNG);
	}
	else
	{
		special6_sorting_a(var, ASCNDNG);
		special6_sorting_b(var, DSCNDNG);
	}
	while (b_size--)
		pa(var);
}

static void	bubble_2stacks_sorting_dscndng(t_var *var, size_t s_size)
{
	size_t	i;
	size_t	b_size;

	i = 0;
	b_size = 0;
	while (s_size > 3 && i < s_size && b_size < s_size / 2)
	{
		if (var->a->index > s_size / 2 && ++b_size)
			pb(var);
		else
			ra(var);
		i++;
	}
	if (s_size > 6)
	{
		bubble_sorting_a(var, s_size - b_size, DSCNDNG);
		bubble_sorting_b(var, b_size, ASCNDNG);
	}
	else
	{
		special6_sorting_a(var, DSCNDNG);
		special6_sorting_b(var, ASCNDNG);
	}
	while (b_size--)
		pa(var);
}

int	bubble_2stacks_sorting(t_var *var, size_t s_size, t_sort mode)
{
	if (mode == ASCNDNG)
		bubble_2stacks_sorting_ascndng(var, s_size);
	else if (mode == DSCNDNG)
		bubble_2stacks_sorting_dscndng(var, s_size);
	return (var->counter);
}

