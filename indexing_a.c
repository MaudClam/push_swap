/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:41:26 by mclam             #+#    #+#             */
/*   Updated: 2021/12/09 15:41:26 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_tree	*alloc_tree_node(t_stack *element)
{
	t_tree	*node;

	node = ft_calloc_lc(1, sizeof(t_tree));
	node->element = element;
	return (node);
}

static t_tree	*add_node_recursive(t_tree *node, t_stack *element)
{
	if (node != NULL)
	{
		if (element->data < node->element->data)
			node->left = add_node_recursive(node->left, element);
		else if (element->data > node->element->data)
			node->right = add_node_recursive(node->right, element);
		else
			ft_simple_errexit("Error");
	}
	else
		node = alloc_tree_node(element);
	return (node);
}

void	build_tree(t_var *var)
{
	t_stack	*tmp;

	tmp = var->a;
	while (tmp != NULL)
	{
		var->root = add_node_recursive(var->root, tmp);
		tmp = tmp->next;
	}
}

static void	indexing_a_recursive(t_tree	*node, size_t *index)
{
	if (node != NULL)
	{
		indexing_a_recursive(node->left, index);
		node->element->index = (*index)++;
		indexing_a_recursive(node->right, index);
	}
}

void	indexing_a(t_var *var)
{
	size_t	index;

	index = 0;
	if (var->root != NULL)
		indexing_a_recursive(var->root, &index);
}
