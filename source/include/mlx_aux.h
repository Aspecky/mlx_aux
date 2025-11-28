/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:17:55 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/28 21:18:29 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AUX_H
# define MLX_AUX_H

# include <mlx42.h>
# include <stdbool.h>

void	pmlx_put_pixel(mlx_image_t *image, int32_t x, int32_t y,
			uint32_t color);
void	mlx_clear_image(mlx_image_t *img);
bool	mlx_resize_texture(mlx_t *mlx, mlx_texture_t *texture,
			uint32_t nwidth, uint32_t nheight);

#endif
