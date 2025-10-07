/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:33:58 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:45:54 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AUX_TYPES_H
# define MLX_AUX_TYPES_H

# include <stdint.h>

typedef struct s_point2d
{
	int32_t	x;
	int32_t	y;
}	t_point2d;

typedef struct s_point3d
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
}	t_point3d;

typedef struct s_line2d
{
	t_point2d	p0;
	t_point2d	p1;
}	t_line2d;

typedef struct s_udim
{
	int32_t	offset;
	double	scale;
}	t_udim;

typedef struct s_udim2
{
	t_udim	x;
	t_udim	y;
}	t_udim2;

typedef struct s_vector2
{
	double	x;
	double	y;	
}	t_vector2;

#endif
