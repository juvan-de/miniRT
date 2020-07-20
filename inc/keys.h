/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/08 14:21:52 by julesvander   #+#    #+#                 */
/*   Updated: 2020/07/20 13:05:41 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# include "../inc/minirt.h"

# define KEY_ESC 53
# define KEY_E 14
# define KEY_D 2
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_SPACE 49
# define KEY_SHIFT 257

typedef struct	s_key
{
	int			key;
	int			(*func)(t_data *, int);
}				t_key;

int				exit_hook(t_data *data, int keycode);
int				next_cam(t_data *data, int keycode);
int				move_cam(t_data *data, int keycode);

t_key			g_hook_key[] = {
	{KEY_ESC, &exit_hook},
	{KEY_E, &next_cam},
	{KEY_A, &move_cam},
	{KEY_D, &move_cam},
	{KEY_S, &move_cam},
	{KEY_W, &move_cam},
	{KEY_SPACE, &move_cam},
	{KEY_SHIFT, &move_cam},
	{0, NULL}
};

#endif
