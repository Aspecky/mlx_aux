/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HookService.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:29:22 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/29 00:46:06 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKSERVICE_H
# define HOOKSERVICE_H

# include <MLX42/MLX42.h>

typedef void	(*t_mousebindfunc)(mouse_key_t button, action_t action,
								modifier_key_t mods, void *param);

typedef struct s_hook_node
{
	void				*data;
	struct s_hook_node	*next;
}	t_hook_node;

typedef struct s_hookservice
{
	mlx_t			*mlx;
	t_hook_node		*key_binds;
	t_hook_node		*mouse_binds;
	t_hook_node		*general_binds;
}	t_hookservice;

t_hookservice	*hookservice_init(mlx_t *mlx);
void			hookservice_free(t_hookservice *service);
int				bind_key(t_hookservice *service, mlx_keyfunc callback,
					void *param, keys_t keys[]);
int				bind_mouse(t_hookservice *service, mlx_mousefunc callback,
					void *param, mouse_key_t keys[]);
int				bind_loop(t_hookservice *service, void (*callback)(void*),
					void *param, double delay);

void			unbind_loop(t_hookservice *service, void (*callback)(void*));
void			unbind_key(t_hookservice *service, mlx_keyfunc callback);

#endif
