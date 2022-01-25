/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:24:48 by mclam             #+#    #+#             */
/*   Updated: 2022/01/25 12:24:48 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	markup_i(t_var *var, size_t s_size, t_sort mode)
{
	t_stack	*tmp;
	size_t	i;
	
	tmp = var->a;
	while(TRUE)
	{
		if (tmp->index == var->markup_i[0])
			break ;
		tmp = fiv(tmp->next != NULL, tmp->next, var->a);
	}
	tmp->stack_a = TRUE;
	tmp = fiv(tmp->next != NULL, tmp->next, var->a);
	i = 0;
	while (++i < s_size)
	{
		if (mode == ASCNDNG && tmp->index - var->markup_i[0] == 1)
		{
			tmp->stack_a = TRUE;
			var->markup_i[0] = tmp->index;
		}
		else if (mode == DSCNDNG && var->markup_i[0] - tmp->index == 1)
		{
			tmp->stack_a = TRUE;
			var->markup_i[0] = tmp->index;
		}
		tmp = fiv(tmp->next == NULL, var->a, tmp->next);
	}
}

//static t_sort	find_way(int first_i, int last_i, int i, int *steps)
//{
//	t_sort	result;
//
//	result = NOT_FOUND;
//	if (first_i != -1)
//	{
//		if (first_i <= i - last_i)
//		{
//			*steps = first_i;
//			result = DIRECT;
//		}
//		else
//		{
//			*steps = i - last_i;
//			result = REVERSE;
//		}
//	}
//	return (result);
//}

//static t_sort	find_nearest_index(t_stack *s, int bit, size_t digit, int *steps)
//{
//	int		first_i;
//	int		last_i;
//	int		i;
//
//	first_i = -1;
//	last_i = -1;
//	i = 0;
//	while (s != NULL)
//	{
//		if ((s->index >> digit) & 1)
//		{
//			first_i = fii(first_i == -1, i, first_i);
//			last_i = i;
//		}
//		i++;
//		s = s->next;
//	}
//	return (find_way(first_i, last_i, i, steps));
//}
