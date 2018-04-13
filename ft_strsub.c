/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:40 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:41:55 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char			*ft_strsub(char const *s, unsigned int start, long long len)
{
	char		*dest;
	long long	i;

	if (!s)
		return (NULL);
	i = 0;
	dest = NULL;
	if (len < 0)
		len = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		while (i < len && s[i])
			dest[i++] = s[start++];
		dest[i] = '\0';
	}
	return (dest);
}
