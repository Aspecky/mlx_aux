/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbind_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:53 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:46:02 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

typedef void	(*t_gen_callback)(void *);

static int	loop_callback_matches(void *data, void *compare_data)
{
	t_genbindinfo	*info;
	t_gen_callback	*callback_ptr;

	info = data;
	callback_ptr = compare_data;
	return (info->callback == *callback_ptr);
}

void	unbind_loop(t_hookservice *service, void (*callback)(void*))
{
	hook_list_remove_if(&service->general_binds, loop_callback_matches,
		&callback, free);
}
