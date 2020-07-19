/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:34:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/19 15:58:51 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	ft_free_objects(t_object *objects)
{
	t_object	*temp;

	while (objects->next)
	{
		temp = objects->next;
		free(objects);
		objects = temp;
	}
	free(objects);
}

void	ft_free_camera(t_cam *cam)
{
	t_cam	*temp;

	while (cam->next)
	{
		temp = cam->next;
		free(cam);
		cam = temp;
	}
	free(cam);
}

void	ft_free_light(t_light *light)
{
	t_light	*temp;

	while (light->next)
	{
		temp = light->next;
		free(light);
		light = temp;
	}
	free(light);
}

void	free_data(t_data *data)
{
	if (data->object)
		ft_free_objects(data->object);
	if (data->cam)
		ft_free_camera(data->cam);
	if (data->light)
		ft_free_light(data->light);
}

void	exit_free(t_data *data, char *error)
{
	write(1, "Error\n", 6);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	if (data)
		free_data(data);
	exit(1);
}
