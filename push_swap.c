/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:22:33 by mclam             #+#    #+#             */
/*   Updated: 2021/12/08 19:23:07 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(const char *argv)
{
	size_t	len;
	
	len = ft_strlen(argv);
	while (len--)
		if (ft_isdigit(argv[len]) == FALSE)
			ft_simple_errexit("Error");
	return(ft_atoi(argv));
}

t_stack	*init_a(int argc, const char **argv)
{
	int		i;
	t_stack	*head_a;
	t_stack	*tmp;
	
	i = 1;
	head_a = NULL;
	if (argc > 1)
	{
		head_a = ft_calloc_lc(1, sizeof(t_stack));
		head_a->data = check_arg(argv[i++]);
		tmp = head_a;
		while (i < argc)
		{
			tmp->next = ft_calloc_lc(1, sizeof(t_stack));
			tmp = tmp->next;
			tmp->data = check_arg(argv[i++]);
		}
	}
	else
		ft_simple_errexit("Error");
	return (head_a);
}

int	main(int argc, const char **argv)
{
	t_var	var;
	
	ft_bzero(&var, sizeof(t_var));
	var.a = init_a(argc, argv);
	build_tree(&var);
	indexing_a(&var);
	rra(&var);
	rra(&var);
	rra(&var);
	rra(&var);
	printf("Hello, World!\n");
	lc(FREE_ALL);
	return (0);
}
