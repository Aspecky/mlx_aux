/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _HookService.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:15:29 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:51:52 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HOOKSERVICE_H
# define _HOOKSERVICE_H

# include <MLX42/MLX42.h>
# include "HookService.h"

typedef struct s_keybindinfo
{
	mlx_keyfunc		callback;
	keys_t			*keys;
	void			*param;
}	t_keybindinfo;

typedef struct s_mousebindinfo
{
	mlx_mousefunc		callback;
	mouse_key_t			*keys;
	void				*param;
}	t_mousebindinfo;

typedef struct s_genbindinfo
{
	void	(*callback)(void *);
	void	*param;
	double	delay;
	double	timer;
}	t_genbindinfo;

t_hook_node	*hook_node_new(void *data);
int			hook_list_append(t_hook_node **head, void *data);
void		hook_list_free(t_hook_node *head, void (*free_func)(void *));
void		hook_list_remove_if(t_hook_node **head, int (*predicate)(void *, void *),
				void *compare_data, void (*free_func)(void *));

#endif
