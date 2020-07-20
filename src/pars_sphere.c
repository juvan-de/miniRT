/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_sphere.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:04:59 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 12:14:20 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	pars_sphere(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (arr_len(input) != 4)
	{
		free(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for sphere."));
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
