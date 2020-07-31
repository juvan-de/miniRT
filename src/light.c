/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 16:37:27 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/31 12:39:48 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static double	light_intensity(t_ray_res *res, t_data *data, t_light *light)
{
	t_ray		ray;
	t_object	*object;
	double		intensity;
	double		len;

	ray.origin = vec_addition(res->cords,
					vec_double_mult(res->normal, SHADOW_BIAS));
	object = data->object;
	ray.direction = normalize_vector(vec_sub(light->cords, ray.origin));
	while (object)
	{
		len = check_collision(&ray, object);
		if (len >= 0 && len <= d3d_distance(ray.origin, light->cords))
			return (0);
		object = object->next;
	}
	intensity = (light->intensity * dotproduct(ray.direction, res->normal));
	intensity = intensity / (4 * M_PI * d3d_distance(res->cords, light->cords));
	return (fmax(0, fmin(intensity * LIGHTMULTIPLIER, 1)));
}

t_color			light_color(t_color light, t_color object)
{
	if (object.r > light.r)
		object.r = light.r;
	if (object.g > light.g)
		object.g = light.g;
	if (object.b > light.b)
		object.b = light.b;
	return (object);
}

int				calc_rgb_to_int(t_color color)
{
	return ((color.r * 65536) + (color.g * 256) + color.b);
}

t_color			add_colors(t_color one, t_color two)
{
	t_color	res;

	res.r = (one.r + two.r);
	if (res.r > 255)
		res.r = 255;
	res.g = (one.g + two.g);
	if (res.g > 255)
		res.g = 255;
	res.b = (one.b + two.b);
	if (res.b > 255)
		res.b = 255;
	return (res);
}

int				full_light_calc(t_ray_res *res, t_data *data)
{
	t_light	*light;
	t_color	color;
	double	intensity;
	t_color	result;
	t_color	temp;

	result = new_color(0, 0, 0);
	temp = new_color(0, 0, 0);
	light = data->light;
	intensity = 0;
	while (light)
	{
		color = light_color(light->color, res->color);
		intensity = light_intensity(res, data, light);
		temp = shade_color(color, intensity);
		result = add_colors(result, temp);
		light = light->next;
	}
	color = light_color(data->amb.color, res->color);
	temp = shade_color(color, data->amb.light);
	result = add_colors(result, temp);
	return (calc_rgb_to_int(result));
}
