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

static void	do_the_operation(t_var *var, char *buf)
{
	t_oper	*tmp;

	tmp = var->ptrs_array;
	while (tmp != NULL && \
					ft_strncmp(tmp->name, buf, ft_strlen(tmp->name) + 1) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		error_exit();
	tmp->ptr(var);
}

static void	read_and_operate(t_var *var)
{
	ssize_t	r;
	int		i;
	char	buf[4];

	r = 1;
	i = 0;
	ft_bzero(&buf, sizeof(buf));
	while (r != 0)
	{
		r = read(STDIN_FILENO, &buf[i], 1);
		if (r == -1)
			ft_simple_errexit("STDIN error");
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			do_the_operation(var, buf);
			i = 0;
			ft_bzero(&buf, sizeof(buf));
		}
		else
			i++;
	}
}

static t_oper	*alloc_operation_ptr(char *name, void (*ptr)(t_var *var))
{
	t_oper	*operation;

	operation = ft_calloc_lc(1, sizeof(t_oper));
	operation->name = name;
	operation->ptr = ptr;
	return (operation);
}

static void	init_oper(t_var *var)
{
	t_oper	*tmp;

	var->ptrs_array = alloc_operation_ptr("sa", sa);
	tmp = var->ptrs_array;
	tmp->next = alloc_operation_ptr("sb", sb);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("ss", ss);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("pa", pa);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("pb", pb);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("ra", ra);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("rb", rb);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("rr", rr);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("rra", rra);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("rrb", rrb);
	tmp = tmp->next;
	tmp->next = alloc_operation_ptr("rrr", rrr);
	tmp = tmp->next;
}

int	main(int argc, const char **argv)
{
	t_var	var;

	if (argc > 1)
	{
		init(&var, argc, argv);
		init_oper(&var);
		var.procedure = TESTING;
		read_and_operate(&var);
		if (is_sorted(var.a, SORTING_MODE) == TRUE && var.b == NULL)
			write(STDOUT_FILENO, "OK\nNumber of operations: ", 25);
		else
			write(STDOUT_FILENO, "KO\nNumber of operations: ", 25);
		ft_putnbr_fd(var.counter, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		lc(FREE_ALL);
	}
	return (0);
}
