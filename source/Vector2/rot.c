/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:35:14 by mtarrih           #+#    #+#             */
/*   Updated: 2026/01/10 19:10:11 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

t_vector2	vector2_rot(t_vector2 a, double theta)
{
	double	cos_theta;
	double	sin_theta;

	if (theta == -M_PI_2)
		return ((t_vector2){a.y, -a.x});
	if (theta == M_PI_2)
		return ((t_vector2){-a.y, a.x});
	if (theta == M_PI)
		return ((t_vector2){-a.x, -a.y});
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	return ((t_vector2){a.x * cos_theta - a.y * sin_theta, a.x * sin_theta + a.y
		* cos_theta});
}

t_ivector2	ivector2_rot(t_ivector2 a, double theta)
{
	double	cos_theta;
	double	sin_theta;

	if (theta == -M_PI_2)
		return ((t_ivector2){a.y, -a.x});
	if (theta == M_PI_2)
		return ((t_ivector2){-a.y, a.x});
	if (theta == M_PI)
		return ((t_ivector2){-a.x, -a.y});
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	return ((t_ivector2){(int)(a.x * cos_theta - a.y * sin_theta), (int)(a.x
			* sin_theta + a.y * cos_theta)});
}
