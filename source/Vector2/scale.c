/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:21:08 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/22 19:44:28 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"

t_vector2	vector2_scale(t_vector2 a, double x)
{
	return ((t_vector2){a.x * x, a.y * x});
}

t_ivector2	ivector2_scale(t_ivector2 a, int x)
{
	return ((t_ivector2){a.x * x, a.y * x});
}
