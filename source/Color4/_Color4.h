/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _Color4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:02:09 by mtarrih           #+#    #+#             */
/*   Updated: 2025/12/13 15:15:55 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COLOR4_H
# define _COLOR4_H

# include <stdint.h>

typedef struct s_color4_to_hsv
{
	double	r;
	double	g;
	double	b;
	uint8_t	alpha;
	double	max;
	double	min;
	double	delta;
}	t_color4_to_hsv;

typedef struct s_color4_from_hsv
{
	double	r;
	double	g;
	double	b;
	double	c;
	double	h_prime;
	double	x;
	double	m;
}	t_color4_from_hsv;

#endif
