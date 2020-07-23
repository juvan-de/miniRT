/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_light.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:57:34 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/23 16:38:07 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	light_add_back(t_data **data, t_light *new)
{
	t_light	*light;

	light = (*data)->light;
	if (!((*data)->light))
	{
		(*data)->light = new;
		return ;
	}
	while (light->next)
	{
		light = light->next;
	}
	light->next = new;
}

void	pars_light(char *line, t_data *data)
{
	char	**input;
	t_light	*temp;

	input = ft_split(line, ' ');
	if (arr_len(input) != 4)
	{
		free(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_light));
	if (!temp)
		return (exit_free(data, "Malloc failed for light"));
	temp->cords = ft_cords_from_scene(input[1]);
	temp->intensity = str_to_double(input[2]);
	temp->color = scene_to_color(input[3]);
	temp->next = 0;
	light_add_back(&data, temp);
	ft_free_array(input);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for light"));
	if (temp->intensity < 0 || temp->intensity > 1)
		return (exit_free(data, "Wrong light intesity"));
	if (temp->color.r == -1)
		return (exit_free(data, "Wrong light color"));
}
