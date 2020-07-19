/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_collision.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:06:17 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 15:35:52 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

static double	check_cylinder_collision_one(t_ray *ray, t_object *cylinder)
{
	t_vector	b[2];
	t_vector	delta_p;
	double		t[2];
	double		abc[2];
	double		discriminant;

	delta_p = vec_sub(ray->origin, cylinder->cords);
	b[0] = vec_sub(ray->direction, vec_double_mult(cylinder->vector,
					dotproduct(ray->direction, cylinder->vector)));
	b[1] = vec_sub(delta_p, vec_double_mult(cylinder->vector,
					dotproduct(delta_p, cylinder->vector)));
	abc[0] = 2 * dotproduct(b[0], b[1]);
	abc[1] = vec_squared(b[1]) - pow(cylinder->size, 2);
	discriminant = pow(abc[0], 2) - 4 * vec_squared(b[0]) * abc[1];
	if (discriminant < 0)
		return (INFINITY);
	else
	{
		t[0] = (-1 * abc[0] + sqrt(discriminant)) / (2 * vec_squared(b[0]));
		t[1] = (-1 * abc[0] - sqrt(discriminant)) / (2 * vec_squared(b[0]));
	}
	if (t[0] > t[1] && t[1] > 0)
		return (t[1]);
	return (t[0]);
}

static double	check_disk_collision(t_ray *ray, t_object *cylinder,
										t_vector *disk)
{
	t_object	temp;
	double		intersect;
	int			i;
	t_vector	v_intersect;

	i = 0;
	temp.vector = cylinder->vector;
	while (i < 2)
	{
		temp.cords = disk[i];
		intersect = check_plane_collision(ray, &temp);
		if (intersect != INFINITY)
		{
			v_intersect = vec_addition(ray->origin,
							vec_double_mult(ray->direction, intersect));
			if (d3d_distance(v_intersect, disk[i]) <= cylinder->size)
				return (intersect);
		}
		i++;
	}
	return (INFINITY);
}

double			check_cylinder_collision(t_ray *ray, t_object *cylinder)
{
	double		res[2];
	t_vector	disk[2];
	t_vector	cord;
	t_vector	angle[2];

	disk[0] = vec_addition(cylinder->cords,
		vec_double_mult(cylinder->vector, cylinder->height / 2));
	disk[1] = vec_sub(cylinder->cords,
		vec_double_mult(cylinder->vector, cylinder->height / 2));
	res[0] = check_disk_collision(ray, cylinder, disk);
	res[1] = check_cylinder_collision_one(ray, cylinder);
	if (res[1] == INFINITY)
		return (res[0]);
	cord = vec_addition(ray->origin, vec_double_mult(ray->direction, res[1]));
	angle[0] = normalize_vector(vec_sub(disk[1], disk[0]));
	angle[1] = normalize_vector(vec_sub(disk[0], disk[1]));
	if (vec_angle(angle[1], vec_sub(disk[0], cord)) < M_PI_2 &&
		vec_angle(angle[0], vec_sub(disk[1], cord)) < M_PI_2 && res[1] < res[0])
		return (res[1]);
	return (res[0]);
}

t_vector		calc_normal_cylinder(t_ray_res *res, t_ray *ray,
							t_object *cylinder)
{
	t_vector	temp;
	t_vector	disk[2];
	double		coll[2];

	disk[0] = vec_addition(cylinder->cords,
		vec_double_mult(cylinder->vector, cylinder->height / 2));
	disk[1] = vec_sub(cylinder->cords,
		vec_double_mult(cylinder->vector, cylinder->height / 2));
	coll[0] = check_disk_collision(ray, cylinder, disk);
	coll[1] = check_cylinder_collision(ray, cylinder);
	if (coll[0] == coll[1] && coll[0] != INFINITY)
	{
		if (vec_angle(cylinder->vector, ray->direction) < M_PI_2)
			return (vec_double_mult(cylinder->vector, -1));
		return (cylinder->vector);
	}
	temp = vec_mult(cylinder->vector, vec_sub(res->cords, cylinder->cords));
	temp = vec_addition(cylinder->cords, temp);
	return (vec_sub(res->cords, temp));
}

void		calc_res_cylinder(t_ray_res *res, t_ray *ray, t_object *cylinder)
{
	res->color = int_to_rgb(cylinder->color);
	res->cords = vec_addition(ray->origin,
						vec_double_mult(ray->direction, res->len));
	res->object = cylinder;
	res->normal = calc_normal_cylinder(res, ray, cylinder);
}
