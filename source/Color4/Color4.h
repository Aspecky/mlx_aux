/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color4.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:02:09 by mtarrih           #+#    #+#             */
/*   Updated: 2025/12/13 15:15:55 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR4_H
# define COLOR4_H

# include <stdint.h>

typedef uint32_t	t_color4;

typedef struct s_color_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	alpha;
}	t_color_rgb;

typedef struct s_color_hsv
{
	double	h;
	double	s;
	double	v;
	uint8_t	alpha;
}	t_color_hsv;

typedef struct s_color_any
{
	double	a;
	double	b;
	double	c;
	uint8_t	alpha;
}	t_color_any;

t_color_rgb	color4_to_rgb(t_color4 color4);
t_color_hsv	color4_to_hsv(t_color4 color4);

t_color4	color4_from_rgb(t_color_rgb rgb);
t_color4	color4_from_hsv(t_color_hsv hsv);
uint32_t	color4_from_hex(const char *hex);

uint32_t	color4_set_a(uint32_t color, uint8_t alpha);

t_color_hsv	lerp_hsv(t_color_hsv src, t_color_hsv dst, double t);

#endif
