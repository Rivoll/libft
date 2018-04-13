/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:35:21 by pkeita            #+#    #+#             */
/*   Updated: 2017/01/17 11:48:10 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		if (n < -9223372036854775807)
		{
			ft_putstr("-9223372036854775808");
			return ;
		}
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
