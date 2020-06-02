/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-de <juvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 15:15:09 by juvan-de       #+#    #+#                */
/*   Updated: 2020/03/12 15:46:28 by juvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/test.h"

int		numlen_base(int num, int base)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = num * -1;
		len++;
	}
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}