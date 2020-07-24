/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:06:07 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/24 13:19:09 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

static void	fill_plane(t_object *temp, char **input)
{
	temp->type = "pl";
	temp->cords = ft_cords_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->color = scene_to_color(input[3]);
	temp->next = 0;
}

void		pars_plane(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (!input)
		return (exit_free(data, "Malloc failed"));
	if (arr_len(input) != 4)
	{
		ft_free_array(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for plane."));
	fill_plane(temp, input);
	ft_free_array(input);
	object_add_back(&data, temp);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for plane"));
	if (temp->vector.x == -5)
		return (exit_free(data, "Wrong vector for plane"));
	if (temp->color.r == -1)
		return (exit_free(data, "Wrong color for plane"));
}
