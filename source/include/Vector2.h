/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarrih <mtarrih@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:19:22 by mtarrih           #+#    #+#             */
/*   Updated: 2025/11/30 18:13:11 by mtarrih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	double	x;
	double	y;	
}	t_vector2;

typedef struct s_ivector2
{
	int	x;
	int	y;	
}	t_ivector2;

t_vector2	vector2_add(t_vector2 a, t_vector2 b);
t_vector2	vector2_sub(t_vector2 a, t_vector2 b);
t_vector2	vector2_mul(t_vector2 a, t_vector2 b);
t_vector2	vector2_scale(t_vector2 a, double x);
t_vector2	vector2_rot(t_vector2 a, double tetha);
t_vector2	vector2_unit(t_vector2 a);
double		vector2_mag(t_vector2 a);

t_ivector2	ivector2_add(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_sub(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_mul(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_scale(t_ivector2 a, int x);
t_ivector2	ivector2_rot(t_ivector2 a, double tetha);
t_ivector2	ivector2_unit(t_ivector2 a);
double		ivector2_mag(t_ivector2 a);

#endif
