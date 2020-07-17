/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_light.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 15:57:34 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/15 17:33:19 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

void	light_add_back(t_data **data, t_light *new)
{
	t_light	*light;

	light = (*data)->light;
	if (!((*data)->light))
	{
		(*data)->light = new;
		return ;
	}
	while (light->next)
	{
		light = light->next;
	}
	light->next = new;
}

void	pars_light(char *line, t_data *data)
{
	char	**input;
	t_light	*temp;

	input = ft_split(line, ' ');
	temp = malloc(sizeof(t_light));
	temp->cords = ft_vector_from_scene(input[1]);
	temp->intensity = str_to_double(input[2]);
	temp->color = int_to_rgb(rgb_to_int(input[3]));
	temp->next = 0;
	light_add_back(&data, temp);
	ft_free_array(input);
	if (temp->cords.x == INFINITY)
		return (exit_free(data, "Wrong cords for light"));
	if (temp->intensity < 0 || temp->intensity > 1)
		return (exit_free(data, "Wrong light intesity"));
	if (temp->color.r == -1)
		return (exit_free(data, "Wrong light color"));
}
