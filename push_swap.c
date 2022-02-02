/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:22:33 by mclam             #+#    #+#             */
/*   Updated: 2021/12/25 15:44:15 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algorithms_testing(t_var *var, int *test, int argc, \
															const char **argv)
{
	var->procedure = TESTING;
	test[0] = bubble_sorting_a(var, var->n, SORTING_MODE);
	lc(FREE_ALL);
	init(var, argc, argv);
	test[1] = bubble_2stacks_sorting(var, var->n, SORTING_MODE);
	lc(FREE_ALL);
	init(var, argc, argv);
	test[2] = fill_stack_b_sorting(var, var->n, SORTING_MODE);
	lc(FREE_ALL);
	init(var, argc, argv);
	test[3] = radix2_sorting(var, var->n, SORTING_MODE);
	lc(FREE_ALL);
	init(var, argc, argv);
	test[4] = radix2_sorting_optmzd(var, var->n, SORTING_MODE);
	lc(FREE_ALL);
	return (find_min(test, 5));
}

static void	execute_best_algorithm(t_var *var, int min)
{
	if (min == 0)
		bubble_sorting_a(var, var->n, SORTING_MODE);
	else if (min == 1)
		bubble_2stacks_sorting(var, var->n, SORTING_MODE);
	else if (min == 2)
		fill_stack_b_sorting(var, var->n, SORTING_MODE);
	else if (min == 3)
		radix2_sorting(var, var->n, SORTING_MODE);
	else if (min == 4)
		radix2_sorting_optmzd(var, var->n, SORTING_MODE);
}

int	main(int argc, const char **argv)
{
	int		test[5];
	int		min;
	t_var	var;

	ft_bzero(&test, sizeof(test));
	min = -1;
	init(&var, argc, argv);
	if (is_sorted(var.a, SORTING_MODE) == FALSE)
	{
		var.procedure = TESTING;
		min = algorithms_testing(&var, test, argc, argv);
		init(&var, argc, argv);
		var.procedure = SORTING;
		execute_best_algorithm(&var, min);
	}
	if (DEBAG_MODE == TRUE)
		print_info(&var, SORTING_MODE, test);
	lc(FREE_ALL);
	return (0);
}
