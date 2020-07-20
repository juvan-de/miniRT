/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:29:14 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:38:30 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)str;
	i = 0;
	while (i < len)
	{
		tmp[i] = 0;
		i++;
	}
	return (str);
}
