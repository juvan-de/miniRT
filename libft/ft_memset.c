/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:36:45 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:39:50 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)str;
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (str);
}
