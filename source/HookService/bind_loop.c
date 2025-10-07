/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:53 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 03:19:34 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

int	bind_loop(t_hookservice *service, void (*callback)(void*),
		void *param, double delay)
{
	t_genbindinfo	*info;

	info = malloc(sizeof(t_genbindinfo));
	if (!info)
		return (0);
	info->callback = callback;
	info->param = param;
	info->delay = delay;
	info->timer = delay;
	if (!sllist_append(service->general_binds, info))
		return (0);
	return (1);
}
