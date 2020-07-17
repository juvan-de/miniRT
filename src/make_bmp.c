/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_bmp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 16:41:05 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/17 14:04:26 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int		calc_filesize(t_data *data)
{
	int	res;
	int	padding;

	res = 54;
	if ((data->res.res_x * 3) % 4 == 0)
		res = res + (data->res.res_x * data->res.res_y * 3);
	else
	{
		padding = ((data->res.res_x * 3) % 4);
		res = res + (data->res.res_y * (data->res.res_x + padding) * 3);
	}
	return (res);
}

void	write_file_header(char *buf, int filesize)
{
	*((uint8_t *)&buf[0]) = (uint8_t)0x42;
	*((uint8_t *)&buf[1]) = (uint8_t)0x4D;
	*((uint32_t *)&buf[2]) = (uint32_t)filesize;
	*((uint32_t *)&buf[10]) = (uint32_t)0x36;
}

void	write_file_info(char *buf, t_data *data)
{
	*((uint32_t *)&buf[14]) = (uint32_t)0x28;
	*((uint32_t *)&buf[18]) = (uint32_t)data->res.res_x;
	*((uint32_t *)&buf[22]) = (uint32_t)data->res.res_y;
	*((uint16_t *)&buf[26]) = (uint16_t)0x01;
	*((uint16_t *)&buf[28]) = (uint16_t)0x18;
}

void	write_file(char *buf, t_data *data)
{
	int		intcolor;
	t_color	color;
	t_pixel	pixel;
	int		index;

	index = 54;
	pixel.y = data->res.res_y - 1;
	while (pixel.y > 0)
	{
		pixel.x = 0;
		while (pixel.x < data->res.res_x)
		{
			intcolor = cast_ray(get_pixel(data, pixel), data->cam->cords, data);
			color = int_to_rgb(intcolor);
			buf[index] = color.b;
			buf[index + 1] = color.g;
			buf[index + 2] = color.r;
			index += 3;
			pixel.x++;
		}
		if ((data->res.res_x * 3) % 4 != 0)
			index += 4 - (data->res.res_x * 3) % 4;
		pixel.y--;
	}
}

void	save_bmp(t_data *data)
{
	int		fd;
	char	*buf;
	int		filesize;

	fd = open("scene.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		exit_free(data, "failed to create bmp.\n");
	filesize = calc_filesize(data);
	buf = ft_calloc(filesize, 1);
	write_file_header(buf, filesize);
	write_file_info(buf, data);
	write_file(buf, data);
	if (write(fd, buf, filesize) < 0)
		return (exit_free(data, "Write failed for bmp\n"));
	if (close(fd) < 0)
		return (exit_free(data, "Failed to close fd"));
	free(buf);
}
