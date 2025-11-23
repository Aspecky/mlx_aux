/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:21:08 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/23 00:57:40 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.h"

t_vector2	vector2_mul(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){a.x * b.x, a.y * b.y});
}

t_ivector2	ivector2_mul(t_ivector2 a, t_ivector2 b)
{
	return ((t_ivector2){a.x * b.x, a.y * b.y});
}
