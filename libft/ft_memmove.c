/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:23:22 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:39:45 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_part_one(char *dest, char *srcs, size_t len)
{
	while (len > 0)
	{
		dest[len - 1] = srcs[len - 1];
		len--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*srcs;

	if (!(src || dst))
		return (0);
	dest = (char*)dst;
	srcs = (char*)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = srcs[i];
			i++;
		}
	}
	else
	{
		ft_memmove_part_one(dest, srcs, len);
	}
	return (dst);
}
