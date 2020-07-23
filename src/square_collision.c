/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_collision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 15:18:23 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/23 16:00:47 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void		calc_res_square(t_ray_res *res, t_ray *ray, t_object *square)
{
	res->cords = vec_addition(ray->origin,
					vec_double_mult(ray->direction, res->len));
	res->color = square->color;
	if (vec_angle(ray->direction, square->vector) < M_PI_2)
		res->normal = vec_double_mult(square->vector, -1);
	else
		res->normal = square->vector;
	res->object = square;
}

int			in_or_out(t_vector hit, t_vector *cords)
{
	t_vector	diff[2];
	t_vector	corner[2];

	diff[0] = vec_sub(cords[0], hit);
	diff[1] = vec_sub(cords[1], hit);
	corner[0] = vec_sub(cords[0], cords[1]);
	corner[1] = vec_sub(cords[1], cords[0]);
	if (vec_angle(corner[0], diff[0]) < M_PI_4 &&
				vec_angle(corner[1], diff[1]) < M_PI_4)
		return (1);
	return (0);
}

double		check_square_collision(t_ray *ray, t_object *square)
{
	t_vector	square_vec[2];
	t_vector	cords[2];
	double		intersect;
	double		vec_len;
	t_vector	intersect_cord;

	intersect = check_plane_collision(ray, square);
	if (intersect == INFINITY)
		return (INFINITY);
	square_vec[0] = calc_orthonormal_vec(square->vector);
	square_vec[1] = crossproduct(square->vector, square_vec[0]);
	vec_len = square->size / 2;
	cords[0] = vec_addition(vec_double_mult(vec_addition(
			vec_double_mult(square_vec[0], -1), square_vec[1]), vec_len),
														square->cords);
	cords[1] = vec_addition(vec_double_mult(vec_addition(square_vec[0],
				vec_double_mult(square_vec[1], -1)), vec_len), square->cords);
	intersect_cord = vec_addition(ray->origin,
							vec_double_mult(ray->direction, intersect));
	if (in_or_out(intersect_cord, cords))
		return (intersect);
	else
		return (INFINITY);
}
