/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:29:32 by juvan-de      #+#    #+#                 */
/*   Updated: 2020/07/20 16:39:07 by julesvander   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = (*lst);
	while (temp)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
}
