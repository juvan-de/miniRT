/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/28 16:23:11 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 12:18:02 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../mlx/mlx.h"

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			hook_frame(t_data *data)
{
	t_pixel	pixel;
	t_mlx	mlx;

	pixel.y = 0;
	mlx = data->mlx;
	while (pixel.y < data->res.res_y)
	{
		pixel.x = 0;
		while (pixel.x < data->res.res_x)
		{
			pixel.x++;
			my_mlx_pixel_put(&mlx.image, pixel.x, pixel.y,
				cast_ray(get_pixel(data, pixel), data->cam->cords, data));
		}
		pixel.y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.image.img, 0, 0);
	return (0);
}

int			exit_hook(t_data *data, int keycode)
{
	t_mlx	mlx;

	(void)keycode;
	mlx = data->mlx;
	mlx_destroy_window(mlx.mlx, mlx.mlx_win);
	free_data(data);
	exit(1);
	return (1);
}

t_mlx		mlx_initialize(t_data *data)
{
	t_mlx	info;

	info.mlx = mlx_init();
	info.mlx_win = mlx_new_window(info.mlx,
					data->res.res_x, data->res.res_y, "MiniRT");
	return (info);
}

int			mlx(t_data *data)
{
	t_image	img;
	t_mlx	mlx;

	mlx = mlx_initialize(data);
	img.img = mlx_new_image(mlx.mlx, data->res.res_x, data->res.res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	data->mlx = mlx;
	data->mlx.image = img;
	mlx_hook(data->mlx.mlx_win, 17, 0L, &exit_hook, data);
	mlx_key_hook(data->mlx.mlx_win, &hook_key, data);
	mlx_loop_hook(mlx.mlx, &hook_frame, data);
	return (0);
}
