/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_square.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:39 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/24 13:20:39 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

t_color		new_color(int r, int g, int b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

void		fill_square(t_object *temp, char **input)
{
	temp->type = "sq";
	temp->cords = ft_cords_from_scene(input[1]);
	temp->vector = normalize_vector(ft_vector_from_scene(input[2]));
	temp->size = ft_atoi_float(input[3]);
	temp->color = scene_to_color(input[4]);
	temp->next = 0;
}

void		pars_square(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (!input)
		return (exit_free(data, "Malloc failed"));
	if (arr_len(input) != 5)
	{
		ft_free_array(input);
		return (exit_free(data, "Incorrect number of arguments."));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for Square"));
	fill_square(temp, input);
	object_add_back(&data, temp);
	ft_free_array(input);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for square"));
	if (temp->color.r == -1)
		return (exit_free(data, "Wrong color for square"));
	if (temp->vector.x == -5)
		return (exit_free(data, "Wrong vector for square."));
	if (temp->size < 0)
		return (exit_free(data, "Wrong size for square"));
}
