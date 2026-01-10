/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:00:00 by mtarrih           #+#    #+#             */
/*   Updated: 2026/01/10 19:13:34 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

t_hook_node	*hook_node_new(void *data)
{
	t_hook_node	*node;

	node = malloc(sizeof(t_hook_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	hook_list_append(t_hook_node **head, void *data)
{
	t_hook_node	*new_node;
	t_hook_node	*current;

	new_node = hook_node_new(data);
	if (!new_node)
		return (0);
	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}

void	hook_list_free(t_hook_node *head, void (*free_func)(void *))
{
	t_hook_node	*current;
	t_hook_node	*next;

	current = head;
	while (current)
	{
		next = current->next;
		if (free_func && current->data)
			free_func(current->data);
		free(current);
		current = next;
	}
}

void	hook_list_remove_if(t_hook_node **head, int (*predicate)(void *,
			void *), void *compare_data, void (*free_func)(void *))
{
	t_hook_node	*current;
	t_hook_node	*prev;
	t_hook_node	*next;

	((void)0, prev = NULL, current = *head);
	while (current)
	{
		next = current->next;
		if (predicate(current->data, compare_data))
		{
			if (prev)
				prev->next = next;
			else
				*head = next;
			if (free_func && current->data)
				free_func(current->data);
			free(current);
			current = next;
		}
		else
		{
			prev = current;
			current = next;
		}
	}
}
