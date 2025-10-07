/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line2d_visible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:09:04 by mtarrih           #+#    #+#             */
/*   Updated: 2025/03/30 00:09:11 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_algorithms.h"
#include "algorithms.h"

static inline int	compute_outcode(t_point2d point, int32_t width,
		int32_t height)
{
	int	outcode;

	outcode = OUTCODE_INSIDE;
	if (point.x < 0)
		outcode |= OUTCODE_LEFT;
	else if (point.x >= width)
		outcode |= OUTCODE_RIGHT;
	if (point.y < 0)
		outcode |= OUTCODE_TOP;
	else if (point.y >= height)
		outcode |= OUTCODE_BOTTOM;
	return (outcode);
}

static inline void	process_intersection2(t_is_line2d_visible *vars,
		int32_t width, int32_t height)
{
	if (vars->outcode_out == vars->outcode0)
	{
		vars->p0 = vars->intersect;
		vars->outcode0 = compute_outcode(vars->p0, width, height);
	}
	else
	{
		vars->p1 = vars->intersect;
		vars->outcode1 = compute_outcode(vars->p1, width, height);
	}
}

static inline void	process_intersection(t_is_line2d_visible *vars,
		int32_t width, int32_t height)
{
	if (vars->outcode1 > vars->outcode0)
		vars->outcode_out = vars->outcode1;
	else
		vars->outcode_out = vars->outcode0;
	if (vars->outcode_out & OUTCODE_TOP)
		vars->intersect = (t_point2d){vars->p0.x + (vars->p1.x - vars->p0.x)
			* (0 - vars->p0.y) / (vars->p1.y - vars->p0.y), 0};
	else if (vars->outcode_out & OUTCODE_BOTTOM)
		vars->intersect = (t_point2d){vars->p0.x + (vars->p1.x - vars->p0.x)
			* (height - 1 - vars->p0.y) / (vars->p1.y - vars->p0.y), height
			- 1};
	else if (vars->outcode_out & OUTCODE_RIGHT)
		vars->intersect = (t_point2d){width - 1, vars->p0.y + (vars->p1.y
				- vars->p0.y) * (width - 1 - vars->p0.x) / (vars->p1.x
				- vars->p0.x)};
	else
		vars->intersect = (t_point2d){0, vars->p0.y + (vars->p1.y - vars->p0.y)
			* (0 - vars->p0.x) / (vars->p1.x - vars->p0.x)};
	process_intersection2(vars, width, height);
}

/*
	Cohen–Sutherland algorithm to check if line is inside the viewport
	https://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
*/
int	is_line2d_visible(t_line2d line, int32_t width, int32_t height)
{
	t_is_line2d_visible	vars;

	vars.p0 = line.p0;
	vars.p1 = line.p1;
	vars.outcode0 = compute_outcode(vars.p0, width, height);
	vars.outcode1 = compute_outcode(vars.p1, width, height);
	while (1)
	{
		if (!(vars.outcode0 | vars.outcode1))
			return (1);
		else if (vars.outcode0 & vars.outcode1)
			return (0);
		else
			process_intersection(&vars, width, height);
	}
}
