/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:56:06 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/26 01:20:27 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

t_vector2	vector2_unit(t_vector2 a, double *magnitude)
{
	double	mag;

	mag = sqrt(a.x * a.x + a.y * a.y);
	if (magnitude)
		*magnitude = mag;
	if (mag == 0)
		return ((t_vector2){0, 0});
	return ((t_vector2){a.x/mag, a.y/mag});
}

t_ivector2	ivector2_unit(t_ivector2 a, double *magnitude)
{
	double	mag;

	mag = sqrt(a.x * a.x + a.y * a.y);
	if (magnitude)
		*magnitude = mag;
	if (mag == 0)
		return ((t_ivector2){0, 0});
	return ((t_ivector2){(int)(a.x/mag), (int)(a.y/mag)});
}
