/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_triangle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:19 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/23 16:39:25 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	fill_triangle(t_object *temp, char **input)
{
	temp->type = "tr";
	temp->cords = ft_cords_from_scene(input[1]);
	temp->second_cord = ft_cords_from_scene(input[2]);
	temp->third_cord = ft_cords_from_scene(input[3]);
	temp->color = scene_to_color(input[4]);
	temp->next = 0;
}

void	pars_triangle(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (arr_len(input) != 5)
	{
		free(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for triangle"));
	fill_triangle(temp, input);
	object_add_back(&data, temp);
	ft_free_array(input);
	if (temp->cords.x == INFINITY ||
		temp->second_cord.x == INFINITY ||
		temp->third_cord.x == INFINITY)
		return (exit_free(data, "Wrong cord for triangle"));
	if (temp->color.r == -1)
		return (exit_free(data, "Wrong color for triangle"));
}
