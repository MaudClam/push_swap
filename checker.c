/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:23:56 by mclam             #+#    #+#             */
/*   Updated: 2022/02/01 21:23:56 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	read_and_operate(t_var *var)
{
	ssize_t	r;
	int		i;
	t_oper	*tmp;
	char	buf[4];

	r = 1;
	i = 0;
	tmp = var->oper;
	ft_bzero(&buf, sizeof(buf));
	while (r != 0)
	{
		r = read(STDIN_FILENO, &buf[i], 1);
		if (r == -1)
			error_exit();
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			while (tmp != NULL && \
				   ft_strncmp(tmp->name, buf, ft_strlen(tmp->name) + 1) != 0)
				tmp = tmp->next;
			if (tmp == NULL)
				error_exit();
			tmp->ptr(var);
			tmp = var->oper;
			ft_bzero(&buf, sizeof(buf));
			i = 0;
		}
		else
			i++;
	}
}

static t_oper	*alloc_oper(char *name, void (*ptr)(t_var *var))
{
	t_oper	*oper;

	oper = ft_calloc_lc(1, sizeof(t_oper));
	oper->name = name;
	oper->ptr = ptr;
	return (oper);
}

static void	init_oper(t_var *var)
{
	t_oper	*tmp;
	
	var->oper = alloc_oper("sa", sa);
	tmp = var->oper;
	tmp->next = alloc_oper("sb", sb);
	tmp = tmp->next;
	tmp->next = alloc_oper("ss", ss);
	tmp = tmp->next;
	tmp->next = alloc_oper("pa", pa);
	tmp = tmp->next;
	tmp->next = alloc_oper("pb", pb);
	tmp = tmp->next;
	tmp->next = alloc_oper("ra", ra);
	tmp = tmp->next;
	tmp->next = alloc_oper("rb", rb);
	tmp = tmp->next;
	tmp->next = alloc_oper("rr", rr);
	tmp = tmp->next;
	tmp->next = alloc_oper("rra", rra);
	tmp = tmp->next;
	tmp->next = alloc_oper("rrb", rrb);
	tmp = tmp->next;
	tmp->next = alloc_oper("rrr", rrr);
	tmp = tmp->next;
}

int	main(int argc, const char **argv)
{
	t_var	var;

	if (argc > 1)
	{
		init(&var, argc, argv);
		init_oper(&var);
		var.operation = TESTING;
		read_and_operate(&var);
		if (is_sorted(var.a, SORTING_MODE) == TRUE)
			write(STDOUT_FILENO, "OK\nNumber of operations: ", 25);
		else
			write(STDOUT_FILENO, "KO\nNumber of operations: ", 25);
		ft_putnbr_fd(var.counter, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
	lc(FREE_ALL);
	return (0);
}
