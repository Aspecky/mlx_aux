/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:47:54 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 03:19:34 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <mlx42.h>

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_hookservice	*service;
	t_slnode		*node;
	t_keybindinfo	*info;
	size_t			i;

	service = param;
	node = service->key_binds->head;
	while (node)
	{
		info = node->data;
		i = 0;
		while (info->keys[i] != (enum keys) - 1)
		{
			if (info->keys[i] == keydata.key)
			{
				info->callback(keydata, info->param);
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

static void	mouse_hook(mouse_key_t button, action_t action,
						modifier_key_t mods, void *param)
{
	t_hookservice	*service;
	t_slnode		*node;
	t_mousebindinfo	*info;
	size_t			i;

	service = param;
	node = service->mouse_binds->head;
	while (node)
	{
		info = node->data;
		i = 0;
		while (info->keys[i] != (enum mouse_key) - 1)
		{
			if (info->keys[i] == button)
			{
				info->callback(button, action, mods, info->param);
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

static void	general_hook(void *param)
{
	t_hookservice	*service;
	t_slnode		*node;
	t_genbindinfo	*info;

	service = param;
	node = service->general_binds->head;
	while (node)
	{
		info = node->data;
		info->timer += service->mlx->delta_time;
		if (info->timer >= info->delay)
		{
			info->timer = 0;
			info->callback(info->param);
		}
		node = node->next;
	}
}

t_hookservice	*hookservice_init(mlx_t *mlx)
{
	static t_hookservice	service;

	service.mlx = mlx;
	service.key_binds = sllist_new();
	service.mouse_binds = sllist_new();
	service.general_binds = sllist_new();
	if (!service.key_binds || !service.mouse_binds || !service.general_binds)
		return (0);
	mlx_key_hook(mlx, key_hook, &service);
	mlx_mouse_hook(mlx, mouse_hook, &service);
	mlx_loop_hook(mlx, general_hook, &service);
	return (&service);
}
