/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 14:07:20 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 15:34:06 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

t_vector	normalize_vector(t_vector vector)
{
	double	temp;
	double	len;

	temp = pythagoras(vector.x, vector.y);
	len = pythagoras(temp, vector.z);
	vector.x = vector.x / len;
	vector.y = vector.y / len;
	vector.z = vector.z / len;
	return (vector);
}

t_vector	new_vector(double a, double b, double c)
{
	t_vector	new;

	new.x = a;
	new.y = b;
	new.z = c;
	return (new);
}

t_vector	vec_addition(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	vec_sub(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}
