/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:45:30 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 03:20:05 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HookService.h"
#include <stdlib.h>

void	hookservice_free(t_hookservice *service)
{
	sllist_free(service->key_binds, free);
	sllist_free(service->mouse_binds, free);
}
