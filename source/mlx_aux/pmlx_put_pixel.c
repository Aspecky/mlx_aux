/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmlx_put_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:40:37 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:45:15 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_aux.h"
#include "mlx42.h"

void	pmlx_put_pixel(mlx_image_t *img, int32_t x, int32_t y, uint32_t color)
{
	uint32_t	pixel_pos;

	if (x >= 0 && y >= 0 && x < (int32_t)img->width
		&& y < (int32_t)img->height)
	{
		pixel_pos = (y * img->width + x) * 4;
		img->pixels[pixel_pos + 0] = (color >> 24) & 0xFF;
		img->pixels[pixel_pos + 1] = (color >> 16) & 0xFF;
		img->pixels[pixel_pos + 2] = (color >> 8) & 0xFF;
		img->pixels[pixel_pos + 3] = color & 0xFF;
	}
}
