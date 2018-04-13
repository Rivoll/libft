/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:53:20 by pkeita            #+#    #+#             */
/*   Updated: 2018/04/09 03:24:59 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fd_data
{
	int		fd;
	char	buff[BUFF_SIZE + 1];
	char	*stock;
}				t_fd_data;

int				get_next_line(const int fd, char **line);
#endif
