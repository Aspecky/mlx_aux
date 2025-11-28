/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbind_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:53 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:46:06 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

static int	key_callback_matches(void *data, void *compare_data)
{
	t_keybindinfo	*info;
	mlx_keyfunc		*callback_ptr;

	info = data;
	callback_ptr = compare_data;
	return (info->callback == *callback_ptr);
}

void	unbind_key(t_hookservice *service, mlx_keyfunc callback)
{
	hook_list_remove_if(&service->key_binds, key_callback_matches,
		&callback, free);
}
