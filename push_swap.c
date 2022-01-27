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

static t_stack	*init_a(int argc, const char **argv)
{
	int		i;
	t_stack	*head_a;
	t_stack	*tmp;

	i = 1;
	head_a = NULL;
	if (argc > 1)
	{
		head_a = ft_calloc_lc(1, sizeof(t_stack));
		head_a->data = push_swap_atoi(argv[i++]);
		tmp = head_a;
		while (i < argc)
		{
			tmp->next = ft_calloc_lc(1, sizeof(t_stack));
			tmp = tmp->next;
			tmp->data = push_swap_atoi(argv[i++]);
		}
	}
	return (head_a);
}

static void	init(t_var *var, int argc, const char **argv)
{
	ft_bzero(var, sizeof(t_var));
	var->a = init_a(argc, argv);
	build_tree(var);
	indexing_a(var);
	var->n = argc - 1;
}

static int	algorithms_testing(t_var *var, int *test, int argc, \
															const char **argv)
{
	var->operation = TESTING;
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

	ft_bzero(test, sizeof(test));
	min = -1;
	init(&var, argc, argv);
	if (is_sorted(var.a, SORTING_MODE) == FALSE)
	{
		min = algorithms_testing(&var, test, argc, argv);
		init(&var, argc, argv);
		var.operation = SORTING;
		execute_best_algorithm(&var, min);
	}
	if (DEBAG_MODE == TRUE)
		print_info(&var, SORTING_MODE, test);
	lc(FREE_ALL);
	return (0);
}
