/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:35:14 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/18 00:38:53 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"
#include <math.h>

t_vector2 vector2_rot(t_vector2 a, double tetha)
{
	return ((t_vector2){a.x * cos(tetha) - a.y * sin(tetha),
						a.x * sin(tetha) + a.y * cos(tetha)});
}
