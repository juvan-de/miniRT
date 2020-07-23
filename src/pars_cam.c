/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cam.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:48:00 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/23 16:49:53 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

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
	temp->cords = ft_cords_from_scene(input[1]);
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
		ft_free_array(input);
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
	if (temp->vector.x == -5)
		return (exit_free(data, "Wrong value for cam vector."));
	if (temp->fov < 0 || temp->fov > 180)
		return (exit_free(data, "Wrong fov value"));
}
