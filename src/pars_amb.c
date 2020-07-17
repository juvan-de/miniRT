/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_amb.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 14:47:55 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/17 14:15:47 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"

double	str_to_double(char *input)
{
	double	res;
	int		temp;

	temp = 0;
	while (input[temp])
	{
		if (ft_isdigit((int)input[temp]) == 0 &&
			input[temp] != '-' && input[temp] != '.')
			return (-1);
		temp++;
	}
	if (input[0] == '-' && ft_atoi(input + 3) != 0)
		return (-1);
	temp = ft_atoi(input);
	res = ft_atoi(input + 2);
	res = res / 10;
	res += temp;
	return (res);
}

int		rgb_to_int(char *input)
{
	int	temp;
	int	temp2;
	int	res;

	temp = ft_atoi(input);
	res = temp * 65536;
	temp2 = ft_atoi(input + numlen_base(temp, 10) + 1);
	res = res + temp2 * 256;
	if (temp < 0 || temp > 255)
		return (-1);
	temp = ft_atoi(input + numlen_base(temp, 10) + numlen_base(temp2, 10) + 2);
	res = res + temp;
	if (temp < 0 || temp > 255 || temp2 < 0 || temp2 > 255)
		return (-1);
	return (res);
}

void	pars_amb(char *line, t_data *data)
{
	char	**input;

	if (data->amb.amb_set == 1)
		return (exit_free(data, "Amb can only be set once."));
	data->amb.amb_set = 1;
	input = ft_split(line, ' ');
	data->amb.light = str_to_double(input[1]);
	data->amb.color = int_to_rgb(rgb_to_int(input[2]));
	ft_free_array(input);
	if (data->amb.light > 1 || data->amb.light < 0)
		return (exit_free(data, "Wrong amb intensity imput."));
	if (data->amb.color.r == -1)
		return (exit_free(data, "Wrong amb color imput."));
}
