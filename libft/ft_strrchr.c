/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:03:23 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:40:48 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;
	char	*res;

	i = ft_strlen(s);
	cc = (char)c;
	while (i >= 0)
	{
		if (s[i] == cc)
		{
			res = (char*)s;
			return (res + i);
		}
		i--;
	}
	return (0);
}
