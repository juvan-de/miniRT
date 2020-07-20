/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:11:47 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:38:34 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	void	*res;
	size_t	i;

	temp = (char*)malloc(count * size);
	if (temp == 0)
		return (0);
	res = temp;
	i = 0;
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (res);
}
