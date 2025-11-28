/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:16:12 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:46:06 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

int	bind_mouse(t_hookservice *service, mlx_mousefunc callback,
				void *param, mouse_key_t keys[])
{
	t_mousebindinfo	*info;

	info = malloc(sizeof(t_mousebindinfo));
	if (!info)
		return (0);
	info->callback = callback;
	info->keys = keys;
	info->param = param;
	if (!hook_list_append(&service->mouse_binds, info))
	{
		free(info);
		return (0);
	}
	return (1);
}
