/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_sphere.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:04:59 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/31 12:47:33 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

static int	vectorcheck(char **array)
{
	int		i;
	int		j;
	char	*goodchars;

	i = 0;
	while (i < 3)
	{
		goodchars = "0123456789.";
		if ((ft_strrchr(goodchars, (int)array[i][0]) == 0 &&
								array[i][0] != '-'))
			return (0);
		j = 1;
		while (array[i][j])
		{
			if (ft_strrchr(goodchars, (int)array[i][j]) == 0)
				return (0);
			if (array[i][j] == '.' || array[i][0] == '.')
				goodchars = "0123456789";
			j++;
		}
		if (array[i][j - 1] == '.')
			return (0);
		i++;
	}
	return (1);
}

t_vector	ft_vector_from_scene(char *input)
{
	t_vector	res;
	int			failcheck;
	char		**array;

	array = ft_split(input, ',');
	if (!array)
		return (new_vector(-5, 0, 0));
	failcheck = 0;
	if (arr_len(array) == 3 && vectorcheck(array) == 1)
	{
		res.x = ft_atoi_float(array[0]);
		res.y = ft_atoi_float(array[1]);
		res.z = ft_atoi_float(array[2]);
		if (res.x >= -1 && res.x <= 1 &&
			res.y >= -1 && res.y <= 1 &&
			res.z >= -1 && res.z <= 1)
			failcheck = 1;
		if (res.x == 0 && res.y == 0 && res.z == 0)
			failcheck = 0;
	}
	ft_free_array(array);
	if (failcheck)
		return (normalize_vector(res));
	return (new_vector(-5, 0, 0));
}

t_vector	ft_cords_from_scene(char *input)
{
	t_vector	res;
	int			failcheck;
	char		**array;

	array = ft_split(input, ',');
	if (!array)
		return (new_vector(INFINITY, 0, 0));
	failcheck = 0;
	if (arr_len(array) == 3 && vectorcheck(array) == 1)
	{
		res.x = ft_atoi_float(array[0]);
		res.y = ft_atoi_float(array[1]);
		res.z = ft_atoi_float(array[2]);
		failcheck = 1;
	}
	ft_free_array(array);
	if (failcheck)
		return (res);
	return (new_vector(INFINITY, 0, 0));
}

static void	fill_sphere(t_object *temp, char **input)
{
	temp->type = "sp";
	temp->cords = ft_cords_from_scene(input[1]);
	temp->size = ft_atoi_float(input[2]);
	temp->color = scene_to_color(input[3]);
	temp->next = 0;
}

void		pars_sphere(char *line, t_data *data)
{
	char		**input;
	t_object	*temp;

	input = ft_split(line, ' ');
	if (!input)
		return (exit_free(data, "Malloc failed"));
	if (arr_len(input) != 4 || numbercheck(input[2]) == 0)
	{
		ft_free_array(input);
		return (exit_free(data, "Incorrect arguments for sphere"));
	}
	temp = malloc(sizeof(t_object));
	if (!temp)
		return (exit_free(data, "Malloc failed for sphere."));
	fill_sphere(temp, input);
	ft_free_array(input);
	object_add_back(&data, temp);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong sphere cord input."));
	if (temp->size < 0)
		return (exit_free(data, "Invalid sphere size."));
	if (temp->color.r == -1)
		return (exit_free(data, "Invalid sphere color"));
}
