/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_sphere.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:04:59 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/07 15:34:52 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	pars_sphere(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	temp = malloc(sizeof(t_object));
	temp->type = "sp";
	temp->cords = ft_vector_from_scene(input[1]);
	temp->size = ft_atoi(input[2]);
	temp->color = rgb_to_int(input[3]);
	temp->next = 0;
	ft_free_array(input);
	object_add_back(&data, temp);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong sphere cord input."));
	if (temp->size < 0)
		return (exit_free(data, "Invalid sphere size."));
	if (temp->color == -1)
		return (exit_free(data, "Invalid sphere color"));
}
