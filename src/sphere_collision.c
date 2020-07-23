/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_collision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 15:50:11 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/23 16:00:38 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	calc_res_sphere(t_ray_res *res, t_ray *ray, t_object *sphere)
{
	res->cords = vec_addition(ray->origin,
		vec_double_mult(ray->direction, res->len));
	res->normal = vec_sub(res->cords, sphere->cords);
	res->normal = normalize_vector(res->normal);
	res->color = sphere->color;
	res->object = sphere;
}

double	check_sphere_collision(t_ray *ray, t_object *sphere)
{
	t_vector	vec;
	double		temp[2];
	double		dist;
	double		t[2];

	vec = vec_sub(sphere->cords, ray->origin);
	temp[0] = dotproduct(vec, ray->direction);
	dist = sqrt(dotproduct(vec, vec) - (temp[0] * temp[0]));
	if (temp[0] >= 0 && dist <= sphere->size)
	{
		temp[1] = sqrt(sphere->size * sphere->size - (dist * dist));
		t[0] = temp[0] - temp[1];
		t[1] = temp[0] + temp[1];
		if (t[0] < t[1] && t[0] > 0)
			return (t[0]);
		return (t[1]);
	}
	return (INFINITY);
}
