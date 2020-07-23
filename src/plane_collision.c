/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_collision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 14:31:49 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/23 16:01:00 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void		calc_res_plane(t_ray_res *res, t_ray *ray, t_object *plane)
{
	res->cords = vec_addition(ray->origin,
				vec_double_mult(ray->direction, res->len));
	res->color = plane->color;
	if (vec_angle(ray->direction, plane->vector) < M_PI_2)
		res->normal = vec_double_mult(plane->vector, -1);
	else
		res->normal = plane->vector;
	res->object = plane;
}

double		check_plane_collision(t_ray *ray, t_object *plane)
{
	t_vector	translation;
	double		temp;
	double		denom;
	double		t;

	denom = dotproduct(ray->direction, plane->vector);
	if (denom >= 0.0000001 || denom <= -0.0000001)
	{
		translation = vec_sub(plane->cords, ray->origin);
		temp = dotproduct(translation, plane->vector);
		t = temp / denom;
		if (t >= 0)
			return (t);
	}
	return (INFINITY);
}
