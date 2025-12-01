/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:35:14 by mtarrih           #+#    #+#             */
/*   Updated: 2025/12/01 16:23:10 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

t_vector2 vector2_rot(t_vector2 a, double theta)
{
	if (theta == -M_PI_2)
		return ((t_vector2){a.y, -a.x});
	if (theta == M_PI_2)
		return ((t_vector2){-a.y, a.x});
	if (theta == M_PI)
		return ((t_vector2){-a.x, -a.y});
	return ((t_vector2){a.x * cos(theta) - a.y * sin(theta),
						a.x * sin(theta) + a.y * cos(theta)});
}

t_ivector2 ivector2_rot(t_ivector2 a, double theta)
{
	if (theta == -M_PI_2)
		return ((t_ivector2){a.y, -a.x});
	if (theta == M_PI_2)
		return ((t_ivector2){-a.y, a.x});
	if (theta == M_PI)
		return ((t_ivector2){-a.x, -a.y});
	return ((t_ivector2){(int)(a.x * cos(theta) - a.y * sin(theta)),
						(int)(a.x * sin(theta) + a.y * cos(theta))});
}
