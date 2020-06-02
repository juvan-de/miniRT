/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   amb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 14:47:55 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 16:36:49 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/test.h"
#include "../libft/libft.h"

static double	str_to_double(char *input)
{
	double	res;

	if (input[0] == '1')
		return (1);
	res = ft_atoi(input + 2);
	res = res / 10;
	return (res);
}

static int	rgb_to_int(char *input)
{
	int	temp;
	int	temp2;
	int	res;

	temp = ft_atoi(input);
	res = temp * 65536;
	temp2 = ft_atoi(input + numlen_base(temp, 10) + 1);
	res = res + temp2 * 256;
	temp = ft_atoi(input + numlen_base(temp, 10) + numlen_base(temp2, 10) + 2);
	res = res + temp;
	return (res);
}

t_data	pars_amb(char *line, t_data data)
{
	char	**input;

	input = ft_split(line, ' ');
	data.amb.light = str_to_double(input[1]);
	data.amb.color = rgb_to_int(input[2]);
	ft_free_array(input);
	return (data);
}