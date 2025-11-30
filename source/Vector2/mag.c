/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:13:14 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/30 18:13:18 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

double	vector2_mag(t_vector2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

double	ivector2_mag(t_ivector2 a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}
