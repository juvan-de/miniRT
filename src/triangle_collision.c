/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_collision.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 10:55:31 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 15:43:50 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void		calc_res_triangle(t_ray_res *res, t_ray *ray, t_object *triangle)
{
	t_vector	vec[2];

	res->cords = vec_addition(ray->origin,
				vec_double_mult(ray->direction, res->len));
	res->color = int_to_rgb(triangle->color);
	vec[0] = vec_sub(triangle->cords, triangle->second_cord);
	vec[1] = vec_sub(triangle->cords, triangle->third_cord);
	res->normal = normalize_vector(crossproduct(vec[0], vec[1]));
	if (vec_angle(ray->direction, res->normal) < M_PI_2)
		res->normal = vec_double_mult(res->normal, -1);
	res->object = triangle;
}

int			inside_out_test(double len, t_object *triangle,
							t_ray *ray, t_vector normal)
{
	t_vector	edge[3];
	t_vector	c[3];
	t_vector	hit;

	hit = vec_addition(ray->origin, vec_double_mult(ray->direction, len));
	edge[0] = vec_sub(triangle->second_cord, triangle->cords);
	edge[1] = vec_sub(triangle->third_cord, triangle->second_cord);
	edge[2] = vec_sub(triangle->cords, triangle->third_cord);
	c[0] = vec_sub(hit, triangle->cords);
	c[1] = vec_sub(hit, triangle->second_cord);
	c[2] = vec_sub(hit, triangle->third_cord);
	if (dotproduct(normal, crossproduct(edge[0], c[0])) > 0 &&
		dotproduct(normal, crossproduct(edge[1], c[1])) > 0 &&
		dotproduct(normal, crossproduct(edge[2], c[2])) > 0)
		return (1);
	return (0);
}

double		check_triangle_collision(t_ray *ray, t_object *triangle)
{
	t_object	plane;
	t_vector	normal;
	double		t;
	t_vector	side[2];

	side[0] = vec_sub(triangle->second_cord, triangle->cords);
	side[1] = vec_sub(triangle->third_cord, triangle->cords);
	normal = crossproduct(side[0], side[1]);
	plane.type = "pl";
	plane.vector = normal;
	plane.cords = triangle->cords;
	t = check_plane_collision(ray, &plane);
	if (inside_out_test(t, triangle, ray, normal))
		return (t);
	return (INFINITY);
}
