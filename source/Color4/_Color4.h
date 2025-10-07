/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _Color4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:02:09 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/31 01:29:56 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COLOR4_H
# define _COLOR4_H

# include <stdint.h>

typedef struct s_color4_to_hsv
{
	float	r;
	float	g;
	float	b;
	uint8_t	alpha;
	float	max;
	float	min;
	float	delta;
}	t_color4_to_hsv;

typedef struct s_color4_from_hsv
{
	float	r;
	float	g;
	float	b;
	float	c;
	float	h_prime;
	float	x;
	float	m;
}	t_color4_from_hsv;

#endif
