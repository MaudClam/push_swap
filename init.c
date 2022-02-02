/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:55:04 by mclam             #+#    #+#             */
/*   Updated: 2022/02/01 22:55:04 by mclam            ###   ########.fr       */
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

void	init(t_var *var, int argc, const char **argv)
{
	ft_bzero(var, sizeof(t_var));
	var->a = init_a(argc, argv);
	build_tree(var);
	indexing_a(var);
	var->n = argc - 1;
}

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	lc(FREE_ALL);
	errno = 255;
	exit (255);
}
