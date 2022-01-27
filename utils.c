/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:47:28 by mclam             #+#    #+#             */
/*   Updated: 2021/12/09 18:47:28 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s, t_sort mode)
{
	while (s != NULL && s->next != NULL)
	{
		if (mode == ASCNDNG && s->data > s->next->data)
			return (FALSE);
		else if (mode == DSCNDNG && s->data < s->next->data)
			return (FALSE);
		s = s->next;
	}
	return (TRUE);
}

int	push_swap_atoi(const char *str)
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

int	find_min(int *a, int i)
{
	int	vol;
	int	idx;

	vol = INT_MAX;
	idx = -1;
	while (i--)
	{
		if (a[i] < vol)
		{
			idx = i;
			vol = a[i];
		}
	}
	return (idx);
}

void	print_stacks(t_var *var)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = var->a;
	tmp_b = var->b;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a != NULL)
		{
			ft_putnbr_fd(tmp_a->data, STDOUT_FILENO);
			write (STDOUT_FILENO, " ", 1);
			tmp_a = tmp_a->next;
		}
		else
			write (STDOUT_FILENO, "  ", 2);
		if (tmp_b != NULL)
		{
			ft_putnbr_fd(tmp_b->data, STDOUT_FILENO);
			tmp_b = tmp_b->next;
		}
		write (STDOUT_FILENO, "\n", 1);
	}
	write (STDOUT_FILENO, "_ _\na b, counter: ", 18);
	ft_putnbr_fd(var->counter, STDOUT_FILENO);
	write (STDOUT_FILENO, "\n", 1);
}

void	print_info(t_var *var, t_sort mode, int *test)
{
	print_stacks(var);
	if (is_sorted(var->a, mode) == TRUE)
		write (STDOUT_FILENO, "Sorting OK\n", 11);
	else
		write (STDOUT_FILENO, "Sorting KO\n", 11);
	ft_putnbr_fd(test[0], STDOUT_FILENO);
	write (STDOUT_FILENO, " bubble_sorting_a\n", 18);
	ft_putnbr_fd(test[1], STDOUT_FILENO);
	write (STDOUT_FILENO, " bubble_2stacks_sorting\n", 24);
	ft_putnbr_fd(test[2], STDOUT_FILENO);
	write (STDOUT_FILENO, " fill_stack_b_sorting\n", 22);
	ft_putnbr_fd(test[3], STDOUT_FILENO);
	write (STDOUT_FILENO, " radix2_sorting\n", 16);
	ft_putnbr_fd(test[4], STDOUT_FILENO);
	write (STDOUT_FILENO, " radix2_sorting_optmzd\n", 23);
}
