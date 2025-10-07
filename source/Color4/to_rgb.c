/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:56:18 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/24 23:10:22 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"

t_color_rgb	color4_to_rgb(uint32_t color)
{
	t_color_rgb	rgb;

	rgb.r = (color >> 24) & 0xFF;
	rgb.g = (color >> 16) & 0xFF;
	rgb.b = (color >> 8) & 0xFF;
	rgb.alpha = color & 0xFF;
	return (rgb);
}
