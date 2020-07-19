/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 15:55:51 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 16:01:04 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	shade_color_2(t_color color, double fraction)
{
	t_color	res;

	res.r = color.r * fraction;
	res.g = color.g * fraction;
	res.b = color.b * fraction;
	return (res);
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
	int	len;

	i = 0;
	len = 0;
	while (array[i] != NULL)
	{
		if (array[i][0] != '\0')
			len++;
		i++;
	}
	return (len);
}
