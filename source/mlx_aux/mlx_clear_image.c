/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:52:54 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:45:29 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_aux.h"
#include "mlx42.h"

void	mlx_clear_image(mlx_image_t *img)
{
	size_t		i;
	size_t		size;
	void		*arr;

	i = 0;
	size = (img->width * img->height) / 2;
	arr = img->pixels;
	while (i < size)
	{
		((uint64_t *)arr)[i] = 0;
		i++;
	}
	if ((img->width * img->height) % 2 != 0)
		*((uint32_t *)arr + (size * 2)) = 0;
}
