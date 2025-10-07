/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:57:05 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/25 03:31:20 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color4.h"
#include "ft_string.h"

static int	hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

uint32_t	color4_from_hex(const char *hex)
{
	t_color_rgb	rgb;
	size_t		len;

	if (*hex == '#')
		hex++;
	rgb = (t_color_rgb){0, 0, 0, 255};
	len = ft_strlen(hex);
	if (len >= 2)
		rgb.r = (hex_to_int(hex[0]) << 4) | hex_to_int(hex[1]);
	if (len >= 4)
		rgb.g = (hex_to_int(hex[2]) << 4) | hex_to_int(hex[3]);
	if (len >= 6)
		rgb.b = (hex_to_int(hex[4]) << 4) | hex_to_int(hex[5]);
	if (len >= 8)
		rgb.alpha = (hex_to_int(hex[6]) << 4) | hex_to_int(hex[7]);
	return (color4_from_rgb(rgb));
}
