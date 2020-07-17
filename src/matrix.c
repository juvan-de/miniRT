/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 14:39:00 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/09 17:39:55 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

t_matrix	normalize_matrix(t_matrix matrix)
{
	matrix.forward = normalize_vector(matrix.forward);
	matrix.right = normalize_vector(matrix.right);
	matrix.up = normalize_vector(matrix.up);
	return (matrix);
}

t_vector	vec_double_sub(t_vector vec, double num)
{
	t_vector res;

	res.x = vec.x - num;
	res.y = vec.y - num;
	res.z = vec.z - num;
	return (res);
}

t_vector	calc_orthonormal_vec(t_vector vec)
{
	t_vector	temp;
	t_vector	res;

	vec = normalize_vector(vec);
	if ((vec.x == 1 || vec.x == -1) && vec.y == 0 && vec.z == 0)
		res = new_vector(0, 1, 0);
	else
		res = new_vector(1, 0, 0);
	temp = res;
	res = vec_double_mult(vec, dotproduct(res, vec));
	res = vec_sub(temp, res);
	res = normalize_vector(res);
	return (res);
}

t_matrix	new_matrix(t_vector vec)
{
	t_matrix	res;

	res.forward = vec_double_mult(vec, -1);
	res.right = calc_orthonormal_vec(res.forward);
	res.up = crossproduct(res.forward, res.right);
	res = normalize_matrix(res);
	return (res);
}

t_vector	vec_matrix_multiplication(t_vector vec, t_matrix mat)
{
	t_vector	res;

	res.x = vec.x * mat.right.x + vec.y * mat.up.x + vec.z * mat.forward.x;
	res.y = vec.x * mat.right.y + vec.y * mat.up.y + vec.z * mat.forward.y;
	res.z = vec.x * mat.right.z + vec.y * mat.up.z + vec.z * mat.forward.z;
	return (res);
}
