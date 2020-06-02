/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 16:44:59 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 17:03:20 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> /*remove later*/
# include <fcntl.h>

# define RES_X data.res.res_x
# define RES_Y data.res.res_y

typedef struct	s_cords
{
	double		x;
	double		y;
	double		z;
}				t_cords;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_mlx
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct	s_res
{
	int			res_x;
	int			res_y;
}				t_res;

typedef struct	s_amb
{
	double		light;
	int			color;
}				t_amb;

typedef struct	s_cam
{
	t_cords		cords;
	t_vector	vector;
	int			fov;
	t_cam		*next;
}				t_cam;

typedef struct	s_data
{
	t_res		res;
	t_mlx		mlx;
	t_amb		amb;
	t_cam		cam;
}				t_data;

typedef struct	s_square
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
}				t_square;

int		mlxtests(void);

/* math functions */

double	get_derivative(t_cords a, t_cords b);

/* parsing functions */

t_data	pars_amb(char *line, t_data data);

/* utils */

int		numlen_base(int num, int base);
void	ft_free_array(char **array);
#endif