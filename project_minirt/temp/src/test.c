/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 15:26:15 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 13:30:03 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/test.h"
#include <math.h>
#include <stdio.h>

t_cords	make_coordinate(int x, int y, int z)
{
	t_cords	cords;

	cords.x = x;
	cords.y = y;
	cords.z = z;
	return (cords);
}

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_square(t_mlx *img, double length, double x_start, double y_start)
{
	int	x;
	int	y;

	x = x_start;
	y = y_start;
	while (y < y_start + length)
	{
		while (x < x_start + length)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			x++;
		}
		x = x_start;
		y++;
	}
}

t_square	get_square(t_cords a, t_cords b, t_cords c)
{
	t_square square;

	if (a.x < b.x && a.x < c.x)
		square.xmin = a.x;
	else if (b.x < a.x && b.x < c.x)
		square.xmin = b.x;
	else if (c.x < a.x && c.x < b.x)
		square.xmin = c.x;
	if (a.x > b.x && a.x > c.x)
		square.xmax = a.x;
	else if (b.x > a.x && b.x > c.x)
		square.xmax = b.x;
	else if (c.x > a.x && c.x > b.x)
		square.xmax = c.x;
	if (a.y < b.y && a.y < c.y)
		square.ymin = a.x;
	else if (b.y < a.y && b.y < c.y)
		square.ymin = b.x;
	else if (c.y < a.y && c.y < b.y)
		square.ymin = c.x;
	if (a.y > b.y && a.y > c.y)
		square.ymax = a.y;
	else if (b.y > a.y && b.y > c.y)
		square.ymax = b.y;
	else if (c.y > a.y && c.y > b.y)
		square.ymax = c.y;
	return (square);
}

int		is_in_middle(double right, double middle, double left)
{
	if (right < middle && middle < left)
		return (1);
	else
		return (0);
}

void	make_triangle(t_mlx *img, t_cords a, t_cords b, t_cords c)
{
	t_cords	cords;
	double	d1;
	double	d2;
	double	d3;
	double	d4;
	t_square square;

	square = get_square(a, b, c);
	cords.x = square.xmin;
	cords.y = square.ymin;
	d1 = get_derivative(a, b);
	d2 = get_derivative(a, c);
	d3 = get_derivative(b, c);
	d4 = get_derivative(b, a);
	while (cords.y < square.ymax)
	{
		while (cords.x < square.xmax)
		{
			if (is_in_middle(d1, get_derivative(a, cords), d2) && is_in_middle(d3, get_derivative(b, cords), d4))
				my_mlx_pixel_put(img, (int)cords.x, (int)cords.y, 0x000000FF);
			cords.x++;
		}
		cords.x = square.xmin;
		cords.y++;
	}
}

void	make_circle(t_mlx *img, double radius, double x_start, double y_start)
{
	double x;
	double y;

	x = x_start - radius;
	y = y_start - radius;
	while (y < y_start + radius)
	{
		while (x < x_start + radius)
		{
			if (hypot(fabs(x - x_start), fabs(y - y_start)) <= radius)
				my_mlx_pixel_put(img, (int)x, (int)y, 0x000000FF);
			x++;
		}
		x = x_start - radius;
		y++;
	}
}

int			mlxtests(void)
{
	void	*mlx;
	void	*mlx_win;
	t_mlx	img;
	t_cords	a;
	t_cords	b;
	t_cords	c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "test");
	img.img = mlx_new_image(mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	a = make_coordinate(0, 0, 0);
	b = make_coordinate(309, 300, 0);
	c = make_coordinate(122, 234, 0);
	make_triangle(&img, a, b, c);
	make_circle(&img, 30, 200, 50);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
