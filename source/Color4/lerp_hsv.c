/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_hsv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:18:08 by mtarrih           #+#    #+#             */
/*   Updated: 2025/12/13 15:15:55 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"

t_color_hsv	lerp_hsv(t_color_hsv src, t_color_hsv dst, double t)
{
	t_color_hsv	hsv;

	hsv.h = src.h + ((dst.h - src.h) * t);
	hsv.s = src.s + ((dst.s - src.s) * t);
	hsv.v = src.v + ((dst.v - src.v) * t);
	hsv.alpha = (uint8_t)((double)src.alpha
			+ ((double)(dst.alpha - src.alpha) *t));
	return (hsv);
}
