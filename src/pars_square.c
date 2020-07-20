/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_square.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:39 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 12:14:25 by julesvander   ########   odam.nl         */
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

t_color		rgb_from_scene(char *input)
{
	int		temp;
	int		temp2;
	t_color	res;

	temp = ft_atoi(input);
	res.r = temp;
	temp2 = ft_atoi(input + numlen_base(temp, 10) + 1);
	res.g = temp2;
	if (temp < 0 || temp > 255)
		return (new_color(-1, 0, 0));
	temp = ft_atoi(input + numlen_base(temp, 10) + numlen_base(temp2, 10) + 2);
	res.b = temp;
	if (temp < 0 || temp > 255 || temp2 < 0 || temp2 > 255)
		return (new_color(-1, 0, 0));
	return (res);
}

void		fill_square(t_object *temp, char **input)
{
	temp->type = "sq";
	temp->cords = ft_vector_from_scene(input[1]);
	temp->vector = normalize_vector(ft_vector_from_scene(input[2]));
	temp->size = ft_atoi_float(input[3]);
	temp->color = rgb_to_int(input[4]);
	temp->next = 0;
}

void		pars_square(char *line, t_data *data)
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
		return (exit_free(data, "Malloc failed for Square"));
	fill_square(temp, input);
	object_add_back(&data, temp);
	ft_free_array(input);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for square"));
	if (temp->color == -1)
		return (exit_free(data, "Wrong color for square"));
	if (temp->vector.x < -1 || temp->vector.x > 1 ||
			temp->vector.y < -1 || temp->vector.y > 1 ||
			temp->vector.z < -1 || temp->vector.z > 1)
		return (exit_free(data, "Wrong vector for square."));
	if (temp->size < 0)
		return (exit_free(data, "Wrong size for square"));
}
