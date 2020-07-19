/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cylinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:29 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 16:07:00 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	fill_cylinder(t_object *temp, char **input)
{
	temp->type = "cy";
	temp->cords = ft_vector_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->size = ft_atoi(input[3]);
	temp->height = ft_atoi(input[4]);
	temp->color = rgb_to_int(input[5]);
	temp->next = 0;
}

void	pars_cylinder(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (arr_len(input) != 6)
	{
		free(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for cylinder"));
	fill_cylinder(temp, input);
	ft_free_array(input);
	if (temp->color == -1 || temp->cords.x == INFINITY)
		return (exit_free(data, "Invalid cylinder color or cords."));
	if (temp->height < 0 || temp->size < 0)
		return (exit_free(data, "Invalid cylinder height or size"));
	if (temp->vector.x < -1 || temp->vector.x > 1 ||
			temp->vector.y < -1 || temp->vector.y > 1 ||
			temp->vector.z < -1 || temp->vector.z > 1)
		return (exit_free(data, "Invalid vector for cylinder"));
	temp->vector = normalize_vector(temp->vector);
	object_add_back(&data, temp);
}