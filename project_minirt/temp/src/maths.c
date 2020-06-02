/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 19:53:59 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/10 20:03:15 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/test.h"

double	get_derivative(t_cords a, t_cords b)
{
	double dv;

	dv = (b.y - a.y) / (b.x - a.x);
	return (dv);
}
