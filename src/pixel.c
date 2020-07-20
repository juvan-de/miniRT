/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 16:03:47 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 12:14:37 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

t_vector	look_at(t_cam *camera, t_vector ray)
{
	t_matrix	matrix;
	t_vector	forward;
	t_vector	right;
	t_vector	up;

	forward = vec_double_mult(camera->vector, -1);
	right = crossproduct(normalize_vector(new_vector(0, 1, 0)), forward);
	up = crossproduct(forward, right);
	matrix.forward = forward;
	matrix.right = right;
	matrix.up = up;
	return (vec_matrix_multiplication(ray, matrix));
}

t_vector	get_pixel(t_data *data, t_pixel pixel)
{
	t_cam		*current;
	t_vector	ray;
	double		fov_frac;

	current = data->cam;
	fov_frac = tan(deg_to_rad(current->fov / 2));
	ray.x = (2 * ((pixel.x + 0.5) / data->res.res_x) - 1) * fov_frac;
	ray.y = -1 * (2 * ((pixel.y + 0.5) / data->res.res_y) - 1) * fov_frac;
	ray.z = -1;
	ray = look_at(current, ray);
	return (normalize_vector(ray));
}
