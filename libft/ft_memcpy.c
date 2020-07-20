/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 16:43:36 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:39:41 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srcs;

	if (dst == '\0' && src == '\0')
		return (dst);
	i = 0;
	dest = (char*)dst;
	srcs = (char*)src;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dst);
}
