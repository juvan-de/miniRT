/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_amb.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 14:47:55 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/24 13:04:50 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

double			str_to_double(char *input)
{
	double	res;
	int		temp;

	temp = 0;
	while (input[temp])
	{
		if (ft_isdigit((int)input[temp]) == 0 &&
			input[temp] != '-' && input[temp] != '.')
			return (-1);
		temp++;
	}
	if (input[0] == '-' && ft_atoi(input + 3) != 0)
		return (-1);
	temp = ft_atoi(input);
	res = ft_atoi(input + 2);
	while (res >= 1)
		res = res / 10;
	while (*(input + 2) == '0')
	{
		res = res / 10;
		input++;
	}
	res += temp;
	return (res);
}

static int		colorcheck(char **array)
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

t_color			scene_to_color(char *input)
{
	t_color	res;
	char	**array;
	int		valid;

	array = ft_split(input, ',');
	if (!array)
		return (new_color(-1, 0, 0));
	valid = 0;
	if (arr_len(array) == 3 && colorcheck(array) == 1)
	{
		res.r = ft_atoi(array[0]);
		res.g = ft_atoi(array[1]);
		res.b = ft_atoi(array[2]);
		if (res.r <= 255 && res.g <= 255 && res.b <= 255)
			valid = 1;
	}
	ft_free_array(array);
	if (valid)
		return (res);
	return (new_color(-1, 0, 0));
}

void			pars_amb(char *line, t_data *data)
{
	char	**input;

	if (data->amb.amb_set == 1)
		return (exit_free(data, "Amb can only be set once."));
	data->amb.amb_set = 1;
	input = ft_split(line, ' ');
	if (!input)
		return (exit_free(data, "Malloc failed"));
	if (arr_len(input) != 3)
	{
		ft_free_array(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	data->amb.light = str_to_double(input[1]);
	data->amb.color = scene_to_color(input[2]);
	ft_free_array(input);
	if (data->amb.light > 1 || data->amb.light < 0)
		return (exit_free(data, "Wrong amb intensity imput."));
	if (data->amb.color.r == -1)
		return (exit_free(data, "Wrong amb color imput."));
}
