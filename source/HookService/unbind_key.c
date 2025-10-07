/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbind_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:53 by mtarrih           #+#    #+#             */
/*   Updated: 2025/10/07 17:45:54 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <SinglyLinkedList.h>
#include <stdlib.h>

void	unbind_key(t_hookservice *service, mlx_keyfunc callback)
{
	t_sllist		*list;
	t_slnode		*prev;
	t_slnode		*node;
	t_slnode		*next;
	t_keybindinfo	*info;

	list = service->key_binds;
	prev = 0;
	node = list->head;
	while (node)
	{
		next = node->next;
		info = node->data;
		if (info->callback == callback)
		{
			sllist_pop(list, node, prev);
			free(info);
			free(node);
			node = prev;
		}
		prev = node;
		node = next;
	}
}
