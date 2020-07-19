/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cam.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:48:00 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/19 15:41:07 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

static int	commacheck(char *input)
{
	int i;

	i = 0;
	while (*input)
	{
		if (*input == ',')
			i++;
		input++;
	}
	if (i == 2)
		return (1);
	return (0);
}

t_vector	ft_vector_from_scene(char *input)
{
	t_vector	res;
	int			i;

	i = 0;
	while (input[i])
	{
		if (ft_isdigit((int)input[i]) == 0 && input[i] != ','
					&& input[i] != '-' && input[i] != '.')
			return (new_vector(INFINITY, 0, 0));
		i++;
	}
	if (!(commacheck(input)))
		return (new_vector(INFINITY, 0, 0));
	res.x = ft_atoi_float(input);
	while (*input && *input != ',')
		input++;
	input++;
	res.y = ft_atoi_float(input);
	while (*input && *input != ',')
		input++;
	input++;
	res.z = ft_atoi_float(input);
	return (res);
}

static void	cam_add_back(t_data **data, t_cam *new)
{
	t_cam	*cam;

	if (!((*data)->cam))
	{
		(*data)->cam = new;
		(*data)->cam->first = new;
		return ;
	}
	cam = (*data)->cam;
	while (cam->next)
	{
		cam = cam->next;
	}
	cam->next = new;
}

void		fill_cam(t_cam *temp, char **input)
{
	temp->cords = ft_vector_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->fov = ft_atoi(input[3]);
	temp->next = 0;
	temp->matrix = new_matrix(normalize_vector(temp->vector));
}

void		pars_cam(char *line, t_data *data)
{
	char	**input;
	t_cam	*temp;

	input = ft_split(line, ' ');
	if (arr_len(input) != 4)
	{
		free(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_cam));
	if (!temp)
		return (exit_free(data, "Malloc failed for cam"));
	fill_cam(temp, input);
	if (data->cam)
		temp->first = data->cam->first;
	ft_free_array(input);
	cam_add_back(&data, temp);
	if (temp->cords.x == INFINITY || temp->vector.x == INFINITY)
		return (exit_free(data, "Wrong cam cord or vector value."));
	if (temp->vector.x < -1 || temp->vector.x > 1 ||
			temp->vector.y < -1 || temp->vector.y > 1 ||
			temp->vector.z < -1 || temp->vector.z > 1)
		return (exit_free(data, "Wrong value for cam vector."));
	if (temp->fov < 0 || temp->fov > 180)
		return (exit_free(data, "Wrong fov value"));
}
