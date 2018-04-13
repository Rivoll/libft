/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atull_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:51:37 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/29 16:51:39 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t		ft_atull_base(char *nb, int base_nb)
{
	size_t	result;
	int		i;

	if (base_nb > 16 || base_nb < 2)
		return (-1);
	i = 0;
	result = 0;
	nb[i] == '+' ? i++ : 0;
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			result = result * base_nb + nb[i++] - '0';
		else if ((nb[i] >= 'a' && nb[i] <= 'j'))
			result = result * base_nb - 87 + nb[i++];
		else if ((nb[i] >= 'A' && nb[i] <= 'J'))
			result = result * base_nb - 55 + nb[i++];
		else
			break ;
	}
	return (result);
}
