/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cylinder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:05:29 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/31 12:49:01 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

int			numbercheck(char *input)
{
	int		i;
	char	*goodchars;

	i = 0;
	goodchars = "0123456789.";
	if ((ft_strrchr(goodchars, (int)input[0]) == 0 &&
						input[0] != '-') || input[0] == '.')
		return (0);
	while (input[i])
	{
		if (ft_strrchr(goodchars, (int)input[i]) == 0)
			return (0);
		if (input[i] == '.')
			goodchars = "1234567890";
		i++;
	}
	if (input[i - 1] == '.')
		return (0);
	return (1);
}

static void	fill_cylinder(t_object *temp, char **input)
{
	temp->type = "cy";
	temp->cords = ft_cords_from_scene(input[1]);
	temp->vector = ft_vector_from_scene(input[2]);
	temp->size = ft_atoi_float(input[3]);
	temp->height = ft_atoi_float(input[4]);
	temp->color = scene_to_color(input[5]);
	temp->next = 0;
}

void		pars_cylinder(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (!input)
		return (exit_free(data, "Malloc failed"));
	if (arr_len(input) != 6 || numbercheck(input[3]) == 0 ||
								numbercheck(input[4]) == 0)
	{
		ft_free_array(input);
		return (exit_free(data, "Incorrect arguments for cylinder"));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for cylinder"));
	fill_cylinder(temp, input);
	ft_free_array(input);
	if (temp->color.r == -1 || temp->cords.x == INFINITY)
		return (exit_free(data, "Invalid cylinder color or cords."));
	if (temp->height < 0 || temp->size < 0)
		return (exit_free(data, "Invalid cylinder height or size"));
	if (temp->vector.x == -5)
		return (exit_free(data, "Invalid vector for cylinder"));
	temp->vector = normalize_vector(temp->vector);
	object_add_back(&data, temp);
}
