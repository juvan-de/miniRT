/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 11:10:01 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/19 16:01:24 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h> /*remove later*/
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define LIGHTMULTIPLIER 50
# define SHADOW_BIAS 1e-4

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	right;
	t_vector	up;
	t_vector	forward;
	t_vector	translation;
}				t_matrix;

typedef struct		s_pixel
{
	unsigned int	x;
	unsigned int	y;
}					t_pixel;

typedef struct		s_ray
{
	t_vector		direction;
	t_vector		origin;
}					t_ray;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	t_image		image;
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef struct	s_res
{
	int				res_set;
	unsigned int	res_x;
	unsigned int	res_y;
}				t_res;

typedef struct	s_amb
{
	int			amb_set;
	double		light;
	t_color		color;
}				t_amb;

typedef struct		s_cam
{
	t_vector		cords;
	t_vector		vector;
	int				fov;
	t_matrix		matrix;
	struct s_cam	*next;
	struct s_cam	*first;
}					t_cam;

typedef struct		s_light
{
	t_vector		cords;
	double			intensity;
	t_color			color;
	struct s_light	*next;
}					t_light;

/* objects */

typedef struct		s_object
{
	char			*type;
	t_vector		cords;
	t_vector		second_cord;
	t_vector		third_cord;
	t_vector		vector;
	int				color;
	double			size;
	double			height;
	struct s_object	*next;
}					t_object;

typedef struct	s_ray_res
{
	t_object	*object;
	t_color		color;
	double		len;
	double		facing_ratio;
	t_vector	normal;
	t_vector	cords;
}				t_ray_res;

typedef struct	s_data
{
	t_res		res;
	t_mlx		mlx;
	t_amb		amb;
	t_cam		*cam;
	t_light		*light;
	t_object	*object;
}				t_data;

int		mlxtests(t_data *data);
int		mlx(t_data *data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
int		hook_key(int keycode, t_data *data);

/* math functions */

double	get_derivative(t_vector a, t_vector b);
double	pythagoras(double a, double b);
double	dotproduct(t_vector a, t_vector b);
double	d3d_distance(t_vector a, t_vector b);
t_vector	calc_normal_sphere(t_vector p_hit, t_object *sphere);

/* parsing functions */

char		*remove_tabs(char *line);
int			rgb_to_int(char *input);
double		str_to_double(char *input);

t_vector	ft_vector_from_scene(char *input);
void		get_parsed(char *line, t_data *data);
void		pars_amb(char *line, t_data *data);
void		pars_light(char *line, t_data *data);
void		pars_cam(char *line, t_data *data);
void		pars_sphere(char *line, t_data *data);
void		pars_triangle(char *line, t_data *data);
void		pars_plane(char *line, t_data *data);
void		pars_square(char *line, t_data *data);
void		pars_cylinder(char *line, t_data *data);
void		object_add_back(t_data **data, t_object *new);

/* raycasting */

void		loop_pixels(t_data *data);
t_vector	get_pixel(t_data *data, t_pixel pixel);
int			cast_ray(t_vector vec, t_vector origin, t_data *data);

/* collisions */

double		check_collision(t_ray *ray, t_object *object);
double		check_sphere_collision(t_ray *ray, t_object *sphere);
void		calc_res_sphere(t_ray_res *res, t_ray *ray, t_object *sphere);
double		check_plane_collision(t_ray *ray, t_object *plane);
void		calc_res_plane(t_ray_res *res, t_ray *ray, t_object *plane);
double		check_square_collision(t_ray *ray, t_object *square);
void		calc_res_square(t_ray_res *res, t_ray *ray, t_object *square);
double		check_triangle_collision(t_ray *ray, t_object *triangle);
void		calc_res_triangle(t_ray_res *res, t_ray *ray, t_object *triangle);
double		check_cylinder_collision(t_ray *ray, t_object *cylinder);
void		calc_res_cylinder(t_ray_res *res, t_ray *ray, t_object *cylinder);

/* Light */

double		full_light_intens(t_ray_res *res, t_data *data);
int			full_light_calc(t_ray_res *res, t_data *data);
t_color		new_color(int r, int g, int b);
/* utils */

int			numlen_base(int num, int base);
double		ft_atoi_float(char *input);
double		deg_to_rad(double degree);
t_color		shade_color_2(t_color color, double fraction);
t_vector	make_cords(double a, double b, double c);
int			arr_len(char **array);
t_color		int_to_rgb(int integer);
/* vector functions */

t_vector	normalize_vector(t_vector vector);
t_vector	new_vector(double a, double b, double c);
t_vector	vec_addition(t_vector a, t_vector b);
t_vector	vec_sub(t_vector a, t_vector b);
t_vector	crossproduct(t_vector a, t_vector b);
t_vector	vec_double_mult(t_vector a, double fraction);
t_vector	vec_double_add(t_vector a, double b);
t_vector	vec_mult(t_vector a, t_vector b);
double		vec_squared(t_vector a);
double		vec_angle(t_vector a, t_vector b);
/* Matrix functions */

t_matrix	normalize_matrix(t_matrix matrix);
t_matrix	new_matrix();
t_vector	calc_orthonormal_vec(t_vector vec);
t_vector	vec_matrix_multiplication(t_vector vec, t_matrix mat);

/* free functions */

void	ft_free_array(char **array);
void	free_data(t_data *data);
void	exit_free(t_data *data, char *error);

void	save_bmp(t_data *data);

#endif
