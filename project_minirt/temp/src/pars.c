/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 14:12:50 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 16:48:30 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../libft/libft.h"
#include "../inc/test.h"

int		ft_error(int num)
{
	if (num == 0)
	{
		ft_putstr_fd("invalid input\n", 1);
	}
	if (num == 1)
	{
		ft_putstr_fd("wrong filename\n", 1);
	}
	return (0);
}

int		check_filename(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] == 't' && name[i - 2] == 'r' && name[i - 3] == '.')
		return (1);
	else
		return (ft_error(1));
}

t_data	pars_res(char *line, t_data data)
{
	char	**input;

	input = ft_split(line, ' ');
	RES_X = ft_atoi(input[1]);
	RES_Y = ft_atoi(input[2]);
	ft_free_array(input);
	return (data);
}

static char	*remove_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

t_data	get_parsed(char *line, t_data data)
{
	if (line[0] == 'R')
		return (pars_res(line, data));
	if (line[0] == 'A')
		return (pars_amb(line, data));
	if (line[0] == 'c')
		return (pars_cam(line, data));
	return (data);
}

t_data		check_input(char *filename)
{
	int 	fd;
	char	*file;
	int		ret;
	t_data	data;

	ret = 1;
	fd = open(filename, O_RDONLY);
	while (ret == 1)
	{
		ret = get_next_line(fd, &file);
		file = remove_tabs(file);
		data = get_parsed(file, data);
		free(file);
	}
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error(0));
	if (check_filename(argv[1]))
		data = check_input(argv[1]);
	return (0);
}
