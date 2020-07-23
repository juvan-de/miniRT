/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 16:13:23 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/23 17:04:09 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../libft/libft.h"
#include "../inc/minirt.h"
#include "../mlx/mlx.h"

int				ft_error(char *message)
{
	ft_putstr_fd(message, 1);
	return (0);
}

static int		check_filename(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] == 't' && name[i - 2] == 'r' && name[i - 3] == '.')
		return (1);
	else
	{
		ft_error("wrong filename\n");
		exit(1);
	}
}

static void		check_input(char *filename, t_data *data)
{
	int		fd;
	char	*file;
	int		ret;

	ret = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ((void)ft_error("Failed to open file."));
	while (ret == 1)
	{
		ret = get_next_line(fd, &file);
		file = remove_tabs(file);
		get_parsed(file, data);
		free(file);
	}
	if (data->amb.amb_set != 1)
		return (exit_free(data, "Ambience not set."));
	if (data->res.res_set != 1)
		return (exit_free(data, "Resolution not set."));
	if (!data->cam)
		return (exit_free(data, "No camera set."));
}

int				main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc != 2 && argc != 3)
		return (ft_error("Incorrect number of arguments.\n"));
	if (check_filename(argv[1]))
		check_input(argv[1], &data);
	if (argc == 2)
	{
		mlx(&data);
		mlx_loop(data.mlx.mlx);
	}
	else if (ft_strncmp("--save", argv[2], ft_strlen("--save") + 1) == 0)
		save_bmp(&data);
	else
		exit_free(&data, "Wrong argument");
	return (0);
}
