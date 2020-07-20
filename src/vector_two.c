/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_two.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 15:32:32 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 12:15:12 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

t_vector	vec_double_mult(t_vector a, double fraction)
{
	t_vector	res;

	res.x = a.x * fraction;
	res.y = a.y * fraction;
	res.z = a.z * fraction;
	return (res);
}

t_vector	vec_double_add(t_vector a, double b)
{
	t_vector	res;

	res.x = a.x + b;
	res.y = a.y + b;
	res.z = a.z + b;
	return (res);
}

t_vector	crossproduct(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_vector	vec_mult(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

double		vec_squared(t_vector a)
{
	return (pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}
