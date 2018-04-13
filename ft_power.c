/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:37:57 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/29 13:38:14 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

ssize_t		ft_power(int base, int power)
{
	int result;

	if (power == 0)
		return (1);
	result = base;
	while (power > 1)
	{
		result *= base;
		--power;
	}
	return (result);
}
