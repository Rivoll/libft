/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atlli_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:46:33 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/07 19:46:34 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

long long int		ft_atlli_base(char *nb, int base_nb)
{
	long long int	result;
	int				sign;
	int				i;

	if (base_nb > 16 || base_nb < 2)
		return (-1);
	sign = 1;
	i = 0;
	result = 0;
	nb[i] == '+' ? i++ : 0;
	nb[i] == '-' ? sign = -1 : 0;
	nb[i] == '-' ? i++ : 0;
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			result = result * base_nb + nb[i++] - '0';
		else if (nb[i] >= 'a' && nb[i] <= 'f')
			result = result * base_nb - 87 + nb[i++];
		else if (nb[i] >= 'A' && nb[i] <= 'F')
			result = result * base_nb - 55 + nb[i++];
		else
			break ;
	}
	return (result * sign);
}

/*
long long int		ft_atllin_base(char *nb, int base_nb, int n)
{
	long long int	result;
	int				sign;
	int				i;

	if (base_nb > 16 || base_nb < 2)
		return (-1);
	sign = 1;
	i = 0;
	result = 0;
	nb[i] == '+' ? i++ : 0;
	nb[i] == '-' ? sign = -1 : 0;
	nb[i] == '-' ? i++ : 0;
	while (nb[i] && i < n)
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			result = result * base_nb + nb[i++] - '0';
		else if (nb[i] >= 'a' && nb[i] <= 'f')
			result = result * base_nb - 87 + nb[i++];
		else if (nb[i] >= 'A' && nb[i] <= 'F')
			result = result * base_nb - 55 + nb[i++];
		else
			break ;
	}
	return (result * sign);
}
*/