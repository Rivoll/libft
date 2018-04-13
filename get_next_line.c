/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:52:55 by pkeita            #+#    #+#             */
/*   Updated: 2018/03/31 08:44:25 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/get_next_line.h"
/*
static t_list	*ft_goto_fd_lst(int fd, t_list *lst)
{
	t_fd_data	*new;

	if (lst->content && ((t_fd_data*)lst->content)->fd == fd)
		return (lst);
	else if (lst->next)
		return (ft_goto_fd_lst(fd, lst->next));
	else
	{
		if (!(new = (t_fd_data*)malloc(sizeof(t_fd_data))))
			return (0);
		new->fd = fd;
		new->current = new->buf + BUFF_SIZE;
		ft_bzero(new->buf, BUFF_SIZE + 1);
		if (!(lst->next = (t_list*)malloc(sizeof(t_list))))
			return (0);
		lst->next->next = 0;
		lst->next->content = new;
		return (lst->next);
	}
}

static int		ft_join_line(char **line, t_fd_data *current_buf)
{
	char			*tmp_line;

	tmp_line = *line;
	*current_buf->current++ = '\0';
	if (!(*line = ft_strjoin(tmp_line, current_buf->buf)))
		return (-1);
	free(tmp_line);
	return (1);
}

static int		ft_use_garbage(char **line, t_fd_data *current)
{
	char	*tmp;
	char	*tmp_line;

	tmp_line = *line;
	if ((tmp = ft_strchr(current->current, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strjoin(*line, current->current)))
			return (-1);
		free(tmp_line);
		current->current = tmp + 1;
		return (1);
	}
	if (!(*line = ft_strjoin(*line, current->current)))
		return (-1);
	free(tmp_line);
	current->current = current->buf + BUFF_SIZE;
	return (0);
}

static int		ft_get_line(const int fd, char **line, t_fd_data *content)
{
	int	tmp;
	int	bool_wrote;

	bool_wrote = 0;
	while ((tmp = read(fd, content->buf, BUFF_SIZE)) > 0)
	{
		bool_wrote = 1;
		content->buf[tmp] = '\0';
		if ((content->current = ft_strchr(content->buf, '\n')))
			return (ft_join_line(line, content));
		content->current = content->buf + tmp;
		if (ft_join_line(line, content) == -1)
			return (-1);
		content->current = content->buf + tmp;
	}
	return ((tmp == -1) ? -1 : bool_wrote);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	list_fd;
	t_list			*current_lst;
	t_fd_data		*content;
	int				bool_wrote;
	int				tmp;

	bool_wrote = 0;
	if (!(current_lst = ft_goto_fd_lst(fd, &list_fd)) || !line)
		return (-1);
	content = current_lst->content;
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (*(content->current))
	{
		if ((tmp = ft_use_garbage(line, content)) || tmp == -1)
			return (tmp);
		bool_wrote = 1;
	}
	if ((tmp = ft_get_line(fd, line, content)) != 0)
		return (tmp);
	free(current_lst->content);
	current_lst->content = 0;
	return (bool_wrote);
}

*/
#include "include/libft.h"
#include "include/get_next_line.h"

static t_list	*ft_check_fd(const int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static int		ft_make_line(char *str, char **line)
{
	int i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] && str[i] != '\n')
			++i;
	}
	else
		i = ft_strlen(str);
	if (i)
		*line = ft_strndup(str, i);
	if (str[i] == '\n')
		return (++i);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	int				len;
	char			*str;
	char			buf[BUFF_SIZE];
	t_list			*begin_list;
	static t_list	*list;

	if (fd < 0 || read(fd, buf, 0))
		return (-1);
	begin_list = list;
	list = ft_check_fd(fd, &begin_list);
	len = 0;
	while (!ft_strchr(list->content, '\n') && (len = read(fd, buf, BUFF_SIZE)))
		list->content = ft_strnjoin(list->content, buf, len);
	len = ft_make_line((char*)list->content, line);
	if (*(char*)list->content == '\0')
	{
		ft_memdel((void**)list);
		return (0);
	}
	str = list->content;
	list->content = ft_strdup(list->content + len);
	free(str);
	list = begin_list;
	return (1);
}
