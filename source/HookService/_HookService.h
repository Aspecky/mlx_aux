/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _HookService.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:15:29 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:40:54 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HOOKSERVICE_H
# define _HOOKSERVICE_H

# include "mlx42.h"

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

#endif
