/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabicmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:23:07 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:50:14 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int			ft_tabicmp(int *tab1, int *tab2, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab1[i] != tab2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}