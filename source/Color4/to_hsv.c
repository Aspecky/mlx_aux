/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hsv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:53:47 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 01:30:10 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"
#include "_Color4.h"
#include <math.h>

static inline t_color4_to_hsv	get_components(t_color4 color)
{
	t_color4_to_hsv	vars;
	t_color_rgb		rgb;

	rgb = color4_to_rgb(color);
	vars.r = (float)rgb.r / 255.0f;
	vars.g = (float)rgb.g / 255.0f;
	vars.b = (float)rgb.b / 255.0f;
	vars.alpha = rgb.alpha;
	vars.max = fmaxf(fmaxf(vars.r, vars.g), vars.b);
	vars.min = fminf(fminf(vars.r, vars.g), vars.b);
	vars.delta = vars.max - vars.min;
	return (vars);
}

t_color_hsv	color4_to_hsv(t_color4 color)
{
	t_color4_to_hsv	vars;
	t_color_hsv		hsv;

	vars = get_components(color);
	if (vars.delta > 0)
	{
		if (vars.max == vars.r)
			hsv.h = 60.0f * fmodf(((vars.g - vars.b) / vars.delta), 6.0f);
		else if (vars.max == vars.g)
			hsv.h = 60.0f * (((vars.b - vars.r) / vars.delta) + 2.0f);
		else
			hsv.h = 60.0f * (((vars.r - vars.g) / vars.delta) + 4.0f);
		if (vars.max > 0)
			hsv.s = (vars.delta / vars.max);
		else
			hsv.s = 0;
	}
	hsv.v = vars.max;
	if (hsv.h < 0)
		hsv.h = 360.0f + hsv.h;
	hsv.alpha = vars.alpha;
	return (hsv);
}
