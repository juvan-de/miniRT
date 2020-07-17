/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: julesvanderhoek <julesvanderhoek@studen      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/08 14:34:13 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/17 14:30:51 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/keys.h"
#include "../mlx/mlx.h"

int		next_cam(t_data *data, int keycode)
{
	t_cam	*cam;

	(void)keycode;
	cam = data->cam;
	if (cam->next)
		data->cam = cam->next;
	else
		data->cam = cam->first;
	return (1);
}

int		move_cam(t_data *data, int keycode)
{
	t_cam *cam;

	cam = data->cam;
	if (keycode == KEY_D)
		cam->cords.x++;
	else if (keycode == KEY_A)
		cam->cords.x--;
	else if (keycode == KEY_SPACE)
		cam->cords.y++;
	else if (keycode == KEY_SHIFT)
		cam->cords.y--;
	else if (keycode == KEY_S)
		cam->cords.z++;
	else if (keycode == KEY_W)
		cam->cords.z--;
	return (1);
}

int		rotate_cam(t_data *data, int keycode)
{
	t_cam	*cam;

	cam = data->cam;
	if (keycode == KEY_RIGHT)
		cam->vector.x++;
	else if (keycode == KEY_LEFT)
		cam->vector.x--;
	else if (keycode == KEY_UP)
		cam->vector.y++;
	else if (keycode == KEY_DOWN)
		cam->vector.y--;
	return (1);
}

int		hook_key(int keycode, t_data *data)
{
	int	i;

	i = 0;
	while (g_hook_key[i].func)
	{
		if (g_hook_key[i].key == keycode)
		{
			g_hook_key[i].func(data, keycode);
			return (0);
		}
		i++;
	}
	return (0);
}
