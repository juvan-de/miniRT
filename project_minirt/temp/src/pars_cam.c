/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_cam.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:48:00 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 17:33:08 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/test.h"
#include "../libft/libft.h"

t_cords	ft_cords_from_scene(char *input)
{
	t_cords	res;
	double	temp;

	temp = ft_atoi(input);
}

t_data	pars_cam(char *line, t_data data)
{
	char	**input;

	input = ft_split(line, ' ');
	data.cam.cords = ft_cords_from_scene(input[1]);
}
