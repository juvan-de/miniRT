/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:34:22 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 16:35:46 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/test.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ; 
}