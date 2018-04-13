/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab2_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:18:30 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/09 11:25:28 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_tab2copy(char **tab_src, char **tab_dest, int x, int y)
{
	int j;

	j = -1;
	if (x < 0)
	{
		while (++j < y)
			ft_strcpy(tab_dest[j], tab_src[j]);
	}
	else
	{
		while (++j < y)
			ft_strncpy(tab_dest[j], tab_src[j], x);
	}
}
