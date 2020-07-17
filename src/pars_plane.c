/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:06:07 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/07 15:35:18 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	pars_plane(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	temp = malloc(sizeof(t_object));
	temp->type = "pl";
	temp->cords = ft_vector_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->color = rgb_to_int(input[3]);
	temp->next = 0;
	ft_free_array(input);
	object_add_back(&data, temp);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for plane"));
	if (temp->vector.x < -1 || temp->vector.x > 1 ||
			temp->vector.y < -1 || temp->vector.y > 1 ||
			temp->vector.z < -1 || temp->vector.z > 1)
		return (exit_free(data, "Wrong vector for plane"));
	if (temp->color == -1)
		return (exit_free(data, "Wrong color for plane"));
}
