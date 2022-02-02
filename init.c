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

static t_stack	*multi_argument_init_a(t_var *var, int argc, const char **argv)
{
	int		i;
	t_stack	*head_a;
	t_stack	*tmp;

	i = 1;
	head_a = ft_calloc_lc(1, sizeof(t_stack));
	head_a->data = push_swap_atoi(argv[i++]);
	tmp = head_a;
	while (i < argc)
	{
		tmp->next = ft_calloc_lc(1, sizeof(t_stack));
		tmp = tmp->next;
		tmp->data = push_swap_atoi(argv[i++]);
	}
	var->n = argc - 1;
	return (head_a);
}

static t_stack	*one_argument_init_a(t_var *var, const char **argv)
{
	size_t	i;
	char	**split;
	t_stack	*head_a;
	t_stack	*tmp;

	i = 0;
	split = ft_splitset_lc(argv[1], " ");
	head_a = ft_calloc_lc(1, sizeof(t_stack));
	var->n = ft_arrsize((const void **)split);
	head_a->data = push_swap_atoi(split[i++]);
	tmp = head_a;
	while (i < var->n)
	{
		tmp->next = ft_calloc_lc(1, sizeof(t_stack));
		tmp = tmp->next;
		tmp->data = push_swap_atoi(split[i++]);
	}
	return (head_a);
}

void	init(t_var *var, int argc, const char **argv)
{
	ft_bzero(var, sizeof(t_var));
	if (argc > 1)
	{
		if (argc == 2)
			var->a = one_argument_init_a(var, argv);
		else
			var->a = multi_argument_init_a(var, argc, argv);
		build_tree(var);
		indexing_a(var);
	}
}

void	error_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	lc(FREE_ALL);
	errno = 255;
	exit (255);
}
