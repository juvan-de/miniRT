/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projecting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 14:14:02 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 16:21:59 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"
#include <math.h>

t_vector		look_at(t_cam *camera, t_vector ray)
{
	t_matrix	matrix;
	t_vector	forward;
	t_vector		right;
	t_vector		up;

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

t_ray_res	*initiate_res(t_ray_res *res)
{
	res->color = new_color(0, 0, 0);
	res->cords = new_vector(INFINITY, INFINITY, INFINITY);
	res->facing_ratio = 0;
	res->len = INFINITY;
	res->normal = new_vector(0, 0, 0);
	return (res);
}

double		check_collision(t_ray *ray, t_object *object)
{
	char	*type;

	type = object->type;
	if (ft_strncmp(type, "sp", 2) == 0)
		return (check_sphere_collision(ray, object));
	if (ft_strncmp(type, "pl", 2) == 0)
		return (check_plane_collision(ray, object));
	if (ft_strncmp(type, "sq", 2) == 0)
		return (check_square_collision(ray, object));
	if (ft_strncmp(type, "tr", 2) == 0)
		return (check_triangle_collision(ray, object));
	if (ft_strncmp(type, "cy", 2) == 0)
		return (check_cylinder_collision(ray, object));
	return (0);
}

void		calc_res(t_ray_res *res, t_ray *ray, t_object *object)
{
	char		*type;

	type = object->type;
	if (ft_strncmp(type, "sp", 2) == 0)
		calc_res_sphere(res, ray, object);
	if (ft_strncmp(type, "pl", 2) == 0)
		calc_res_plane(res, ray, object);
	if (ft_strncmp(type, "sq", 2) == 0)
		calc_res_square(res, ray, object);
	if (ft_strncmp(type, "tr", 2) == 0)
		calc_res_triangle(res, ray, object);
	if (ft_strncmp(type, "cy", 2) == 0)
		calc_res_cylinder(res, ray, object);
}

int			cast_ray(t_vector vec, t_vector origin, t_data *data)
{
	t_ray		ray;
	t_ray_res	res;
	double		len;
	t_object	*object;

	ray.direction = vec;
	ray.origin = origin;
	object = data->object;
	res = *(initiate_res(&res));
	while (object)
	{
		len = check_collision(&ray, object);
		if (len != INFINITY && len <= res.len && len >= 0)
		{
			res.len = len;
			calc_res(&res, &ray, object);
		}
		object = object->next;
	}
	if (res.len != INFINITY)
		return (full_light_calc(&res, data));
	return (0);
}
