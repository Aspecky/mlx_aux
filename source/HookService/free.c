/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:45:30 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:46:06 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include "_HookService.h"
#include <stdlib.h>

void	hookservice_free(t_hookservice *service)
{
	hook_list_free(service->key_binds, free);
	hook_list_free(service->mouse_binds, free);
	hook_list_free(service->general_binds, free);
}
