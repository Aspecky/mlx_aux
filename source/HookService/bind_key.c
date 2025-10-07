/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:16:12 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 03:19:34 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

int	bind_key(t_hookservice *service, mlx_keyfunc callback,
		void *param, keys_t keys[])
{
	t_keybindinfo	*info;

	info = malloc(sizeof(t_keybindinfo));
	if (!info)
		return (0);
	info->callback = callback;
	info->keys = keys;
	info->param = param;
	if (!sllist_append(service->key_binds, info))
		return (0);
	return (1);
}
