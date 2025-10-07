/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_hsv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:18:08 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:32:02 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"

t_color_hsv	lerp_hsv(t_color_hsv src, t_color_hsv dst, float t)
{
	t_color_hsv	hsv;

	hsv.h = src.h + ((dst.h - src.h) * t);
	hsv.s = src.s + ((dst.s - src.s) * t);
	hsv.v = src.v + ((dst.v - src.v) * t);
	hsv.alpha = (uint8_t)((float)src.alpha
			+ ((float)(dst.alpha - src.alpha) *t));
	return (hsv);
}
