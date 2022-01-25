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

void	print_info(t_var *var, int test1, int test2, int test3, int test4)
{
	print_stacks(var);
	ft_putnbr_fd(test1, STDOUT_FILENO);
	write (STDOUT_FILENO, " bubble_sorting_a\n", 18);
	ft_putnbr_fd(test2, STDOUT_FILENO);
	write (STDOUT_FILENO, " bubble_2stacks_sorting\n", 24);
	ft_putnbr_fd(test3, STDOUT_FILENO);
	write (STDOUT_FILENO, " stackb_fill_sorting\n", 21);
	ft_putnbr_fd(test4, STDOUT_FILENO);
	write (STDOUT_FILENO, " radix2_sorting\n", 16);
//	int i = 500;
//	while (i--)
//		printf("%d ", i);
}
