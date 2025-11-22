/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:19:22 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/18 00:41:10 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	double	x;
	double	y;	
}	t_vector2;

t_vector2	vector2_add(t_vector2 a, t_vector2 b);
t_vector2	vector2_sub(t_vector2 a, t_vector2 b);
t_vector2	vector2_scale(t_vector2 a, double x);
t_vector2	vector2_rot(t_vector2 a, double tetha);

#endif
