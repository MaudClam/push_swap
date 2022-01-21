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

static int	push_swap_atoi(const char *str)
{
	unsigned long int	nbr;
	int					sign;
	int					i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && nbr - 1 > INT_MAX))
			ft_simple_errexit("Error");
		i++;
	}
	if (str[i] != 0)
		ft_simple_errexit("Error");
	return ((int)nbr * sign);
}

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

int	main(int argc, const char **argv)
{
	t_var	var;
	int		test1;
	int		test2;
	int		test3;

	test1 = 0;
	test2 = 0;
	test3 = 0;
	init(&var, argc, argv);
	if (is_sorted(var.a, SORTING_MODE) == FALSE)
	{
		test1 = bubble_sorting_a(&var, var.n, SORTING_MODE);
		lc(FREE_ALL);
		init(&var, argc, argv);
		test2 = bubble_2stack_sorting(&var, var.n, SORTING_MODE);
		lc(FREE_ALL);
		init(&var, argc, argv);
		test3 = stackb_fill_sorting(&var, var.n, SORTING_MODE);
		lc(FREE_ALL);
		init(&var, argc, argv);
		var.operation = SORTING;
		if (test1 <= test2 && test1 <= test3)
			bubble_sorting_a(&var, var.n, SORTING_MODE);
		else if (test2 <= test1 && test2 <= test3)
			bubble_2stack_sorting(&var, var.n, SORTING_MODE);
		else if (test3 <= test1 && test3 <= test2)
			stackb_fill_sorting(&var, var.n, SORTING_MODE);
	}
	if (DEBAG_MODE == TRUE)
		print_info(&var, test1, test2, test3);
	lc(FREE_ALL);
	return (0);
}
