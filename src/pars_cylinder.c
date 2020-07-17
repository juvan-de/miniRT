/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cylinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:29 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/13 17:45:00 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	pars_cylinder(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	temp = malloc(sizeof(t_object));
	temp->type = "cy";
	temp->cords = ft_vector_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->size = ft_atoi(input[3]);
	temp->height = ft_atoi(input[4]);
	temp->color = rgb_to_int(input[5]);
	temp->next = 0;
	ft_free_array(input);
	if (temp->color == -1)
		return (exit_free(data, "Invalid cylinder color"));
	if (temp->height < 0 || temp->size < 0)
		return (exit_free(data, "Invalid cylinder height or size"));
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Invalid cords for cylinder"));
	if (temp->vector.x < -1 || temp->vector.x > 1 ||
			temp->vector.y < -1 || temp->vector.y > 1 ||
			temp->vector.z < -1 || temp->vector.z > 1)
		return (exit_free(data, "Invalid vector for cylinder"));
	temp->vector = normalize_vector(temp->vector);
	object_add_back(&data, temp);
}
