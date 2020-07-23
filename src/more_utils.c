/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 15:55:51 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/23 17:29:15 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/minirt.h"

t_color	shade_color(t_color color, double fraction)
{
	t_color	res;

	res.r = color.r * fraction;
	res.g = color.g * fraction;
	res.b = color.b * fraction;
	return (res);
}

t_color	int_to_rgb(int integer)
{
	t_color	color;

	if (integer == -1)
		return (new_color(-1, 0, 0));
	color.r = (integer / 65536);
	integer = (integer - (color.r * 65536));
	color.g = integer / 256;
	integer = (integer - (color.g * 256));
	color.b = integer;
	return (color);
}

int		colorcheck(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (array[i][j])
		{
			if (!ft_isdigit((int)array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
