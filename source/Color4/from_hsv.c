/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_hsv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:59:43 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:31:45 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"
#include "_Color4.h"
#include <math.h>

static inline void	init_hsv_convert(t_color4_from_hsv *conv, t_color_hsv hsv)
{
	conv->r = 0;
	conv->g = 0;
	conv->b = 0;
	conv->c = hsv.v * hsv.s;
	conv->h_prime = fmodf(hsv.h / 60.0f, 6);
	conv->x = conv->c * (1 - fabsf(fmodf(conv->h_prime, 2) - 1));
	conv->m = hsv.v - conv->c;
}

static inline void	set_rgb_values(t_color4_from_hsv *conv)
{
	if (0 <= conv->h_prime && conv->h_prime < 1)
		((void)conv, conv->r = conv->c, conv->g = conv->x, conv->b = 0);
	else if (1 <= conv->h_prime && conv->h_prime < 2)
		((void)conv, conv->r = conv->x, conv->g = conv->c, conv->b = 0);
	else if (2 <= conv->h_prime && conv->h_prime < 3)
		((void)conv, conv->r = 0, conv->g = conv->c, conv->b = conv->x);
	else if (3 <= conv->h_prime && conv->h_prime < 4)
		((void)conv, conv->r = 0, conv->g = conv->x, conv->b = conv->c);
	else if (4 <= conv->h_prime && conv->h_prime < 5)
		((void)conv, conv->r = conv->x, conv->g = 0, conv->b = conv->c);
	else if (5 <= conv->h_prime && conv->h_prime < 6)
		((void)conv, conv->r = conv->c, conv->g = 0, conv->b = conv->x);
}

static t_color_rgb	convert_to_rgb(t_color4_from_hsv *conv, uint8_t alpha)
{
	t_color_rgb	rgb;

	conv->r += conv->m;
	conv->g += conv->m;
	conv->b += conv->m;
	rgb.r = (uint8_t)(conv->r * 255);
	rgb.g = (uint8_t)(conv->g * 255);
	rgb.b = (uint8_t)(conv->b * 255);
	rgb.alpha = alpha;
	return (rgb);
}

t_color4	color4_from_hsv(t_color_hsv hsv)
{
	t_color4_from_hsv	conv;
	t_color_rgb			rgb;

	init_hsv_convert(&conv, hsv);
	set_rgb_values(&conv);
	rgb = convert_to_rgb(&conv, hsv.alpha);
	return (color4_from_rgb(rgb));
}
