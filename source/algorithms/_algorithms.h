/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _algorithms.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:07:36 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:03:41 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALGORITHMS_H
# define _ALGORITHMS_H

# include "mlx_aux_types.h"

# define OUTCODE_INSIDE 0
# define OUTCODE_LEFT 1
# define OUTCODE_RIGHT 2
# define OUTCODE_BOTTOM 4
# define OUTCODE_TOP 8

typedef struct s_is_line2d_visible
{
	t_point2d	p0;
	t_point2d	p1;
	int			outcode0;
	int			outcode1;
	t_point2d	intersect;
	int			outcode_out;
}	t_is_line2d_visible;

#endif
