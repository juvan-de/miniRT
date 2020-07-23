/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 14:12:50 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/23 17:24:58 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../libft/libft.h"
#include "../inc/minirt.h"
#include "../mlx/mlx.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	object_add_back(t_data **data, t_object *new)
{
	t_object	*object;

	object = (*data)->object;
	if (!(*data)->object)
	{
		(*data)->object = new;
		return ;
	}
	while (object->next)
	{
		object = object->next;
	}
	object->next = new;
}

void	pars_res(char *line, t_data *data)
{
	char	**input;
	int		screen[2];

	if (data->res.res_set == 1)
		return (exit_free(data, "Res can only be set once."));
	data->res.res_set = 1;
	input = ft_split(line, ' ');
	if (arr_len(input) != 3 || numbercheck(input[1]) == 0
						|| numbercheck(input[2]) == 0)
	{
		ft_free_array(input);
		exit_free(data, "wrong arguments for res");
	}
	data->res.res_x = ft_atoi(input[1]);
	data->res.res_y = ft_atoi(input[2]);
	ft_free_array(input);
	mlx_get_screen_size(data->mlx.mlx, &screen[0], &screen[1]);
	if (data->res.res_x > screen[0])
		data->res.res_x = screen[0];
	if (data->res.res_y > screen[1])
		data->res.res_y = screen[1];
	if (data->res.res_x <= 0)
		return (exit_free(data, "Wrong x-resolution."));
	if (data->res.res_y <= 0)
		return (exit_free(data, "Wrong y-resolution."));
}

char	*remove_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

void	get_parsed(char *line, t_data *data)
{
	if (line[0] == 'R')
		pars_res(line, data);
	else if (line[0] == 'A')
		pars_amb(line, data);
	else if (line[0] == 'c' && line[1] != 'y')
		pars_cam(line, data);
	else if (line[0] == 'l')
		pars_light(line, data);
	else if (line[0] == 's' && line[1] == 'p')
		pars_sphere(line, data);
	else if (line[0] == 't' && line[1] == 'r')
		pars_triangle(line, data);
	else if (line[0] == 'p' && line[1] == 'l')
		pars_plane(line, data);
	else if (line[0] == 's' && line[1] == 'q')
		pars_square(line, data);
	else if (line[0] == 'c' && line[1] == 'y')
		pars_cylinder(line, data);
}
