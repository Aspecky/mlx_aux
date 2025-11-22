/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_resize_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/21 00:54:57 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_aux.h"
#include <ft_string.h>
#include <mlx42.h>
#include <stdlib.h>

bool	mlx_resize_texture(mlx_t *mlx, mlx_texture_t *texture,
			uint32_t nwidth, uint32_t nheight)
{
	mlx_image_t	*img;
	uint8_t		*new_pixels;
	size_t		new_size;

	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		return (false);
	if (!mlx_resize_image(img, nwidth, nheight))
	{
		mlx_delete_image(mlx, img);
		return (false);
	}
	new_size = nwidth * nheight * texture->bytes_per_pixel;
	new_pixels = malloc(new_size);
	if (!new_pixels)
	{
		mlx_delete_image(mlx, img);
		return (false);
	}
	ft_memcpy(new_pixels, img->pixels, new_size);
	free(texture->pixels);
	texture->pixels = new_pixels;
	texture->width = nwidth;
	texture->height = nheight;
	mlx_delete_image(mlx, img);
	return (true);
}
