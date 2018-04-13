/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:57:43 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/23 05:11:09 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t		ft_find_next_prim(size_t nbr)
{
	size_t i;

	i = 2;
	if (nbr == 1)
		return (2);
	while (nbr <= ULONG_MAX)
	{
		i = 2;
		while (nbr % i != 0 && i + i < nbr)
			i++;
		if (nbr % i != 0)
			return (nbr);
		nbr++;
	}
	return (0);
}
