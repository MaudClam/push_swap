/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:36:48 by mclam             #+#    #+#             */
/*   Updated: 2022/01/27 21:36:48 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_a_to_b(t_var *var, size_t i, size_t *b_size, t_sort mode)
{
	if ((var->a->index >> i & 1) == fis(mode == ASCNDNG, 1, 0))
		ra(var);
	else
	{
		pb(var);
		(*b_size)++;
	}
}

static void	from_b_to_a(t_var *var, size_t i, size_t *b_size, t_sort mode)
{
	if ((var->b->index >> i & 1) == fis(mode == ASCNDNG, 0, 1))
		rb(var);
	else
	{
		pa(var);
		(*b_size)--;
	}
}

int	radix2_sorting_optmzd(t_var *var, size_t s_size, t_sort mode)
{
	size_t	max_bits;
	size_t	i;
	size_t	j;
	size_t	b_size;

	max_bits = 0;
	while ((s_size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	b_size = 0;
	while (i < max_bits && is_sorted(var->a, mode) != TRUE)
	{
		j = s_size - b_size;
		while (j-- && is_sorted(var->a, mode) != TRUE)
			from_a_to_b(var, i, &b_size, mode);
		i++;
		j = b_size;
		while (j-- && i < max_bits)
			from_b_to_a(var, i, &b_size, mode);
	}
	while (var->b != NULL)
		pa(var);
	return (var->counter);
}
