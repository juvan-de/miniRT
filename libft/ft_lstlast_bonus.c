/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:05:07 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:39:19 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list *temp;

	temp = lst;
	if (temp == 0)
		return (0);
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	return (temp);
}
