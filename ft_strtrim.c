/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:26:10 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/06 15:48:47 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	char	*dest;
	int		i;
	int 	j;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (ft_isblank(s[i]))
		i++;
	if (len < 0 || len < i)
		return (ft_strnew(0));
	j = 0;
	while (ft_isblank(s[len]))
		len--;
	dest = ft_strnew(len - i + 1);
	while (i <= len)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
