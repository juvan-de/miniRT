/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 19:53:59 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/19 15:31:39 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double		get_derivative(t_vector a, t_vector b)
{
	double dv;

	dv = (b.y - a.y) / (b.x - a.x);
	return (dv);
}

double		pythagoras(double a, double b)
{
	return (sqrt((a * a) + (b * b)));
}

double		d3d_distance(t_vector a, t_vector b)
{
	double	temp;

	temp = pythagoras(b.x - a.x, b.y - a.y);
	return (pythagoras(temp, b.z - a.z));
}

double		dotproduct(t_vector a, t_vector b)
{
	return (a.x * b.x + (a.y * b.y) + (a.z * b.z));
}

t_vector	calc_normal_sphere(t_vector p_hit, t_object *sphere)
{
	t_vector	n_hit;

	n_hit.x = p_hit.x - sphere->cords.x;
	n_hit.y = p_hit.y - sphere->cords.y;
	n_hit.z = p_hit.z - sphere->cords.z;
	return (normalize_vector(n_hit));
}
