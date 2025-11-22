/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:35:14 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/22 19:44:28 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

t_vector2 vector2_rot(t_vector2 a, double tetha)
{
	return ((t_vector2){a.x * cos(tetha) - a.y * sin(tetha),
						a.x * sin(tetha) + a.y * cos(tetha)});
}

t_ivector2 ivector2_rot(t_ivector2 a, double tetha)
{
	return ((t_ivector2){(int)(a.x * cos(tetha) - a.y * sin(tetha)),
						(int)(a.x * sin(tetha) + a.y * cos(tetha))});
}
