/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 15:15:09 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:16:11 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

int		numlen_base(int num, int base)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = num * -1;
		len++;
	}
	if (num == 0)
		len++;
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

double		ft_atoi_float(char *input)
{
	double	res;
	double	temp;
	int		i;
	int		fraction;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	if (input[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (input[i] >= '0' && input[i] <= '9')
	{
		res *= 10;
		res += (input[i] - '0');
		i++;
	}
	fraction = 1;
	if (input[i] == '.')
	{
		i++;
		while (input[i] >= '0' && input[i] <= '9')
		{
			fraction *= 10;
			temp = input[i] - '0';
			temp = temp / fraction;
			res += temp;
			i++;
		}
	}
	return (res * neg);
}

double	vec_angle(t_vector a, t_vector b)
{
	double	temp[3];

	temp[0] = dotproduct(a, b);
	temp[1] = d3d_distance(a, new_vector(0,0,0));
	temp[2] = d3d_distance(b, new_vector(0,0,0));
	return (acos(temp[0] / (temp[1] * temp[2])));
}

double	deg_to_rad(double degree)
{
	return (degree * (M_PI / 180));
}

int		shade_color(int integer, double fraction)
{
	int	red;
	int	green;
	int	blue;

	red = (integer / 65536);
	integer = (integer - (red * 65536));
	red *= fraction;
	green = integer / 256;
	integer = (integer - (green * 256));
	green *= fraction;
	blue = integer * fraction;
	integer = blue + (green * 256) + (red * 65536);
	return (integer);
}

t_color		int_to_rgb(int integer)
{
	t_color	color;

	color.r = (integer / 65536);
	integer = (integer - (color.r * 65536));
	color.g = integer / 256;
	integer = (integer - (color.g * 256));
	color.b = integer;
	return (color);
}

int		arr_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	return (i);
}
