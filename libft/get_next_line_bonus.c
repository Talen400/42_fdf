/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/26 14:07:25 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd_list	*ft_get(t_fd_list **head, int fd)
{
	t_fd_list	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_fd_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->rest = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

static void	ft_remove(t_fd_list **head, int fd)
{
	t_fd_list	*previous;
	t_fd_list	*node;

	previous = NULL;
	node = *head;
	while (node)
	{
		if (node->fd == fd)
		{
			if (previous)
				previous->next = node->next;
			else
				*head = node->next;
			free(node->rest);
			free(node);
			return ;
		}
		previous = node;
		node = node->next;
	}
}

static char	*ft_buffering(int fd, char *rest, char *tmp)
{
	ssize_t		nbyte;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (rest);
}

static char	*ft_rest(char **rest)
{
	char	*line;
	char	*tmp;
	char	*nl;

	if (!*rest || !**rest)
		return (NULL);
	nl = ft_strchr(*rest, '\n');
	if (nl)
	{
		line = ft_substr(*rest, 0, nl - *rest + 1);
		tmp = ft_strdup(nl + 1);
		free(*rest);
		*rest = tmp;
	}
	else
	{
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*fd_node;
	char				*line;
	char				*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = ft_get(&fd_list, fd);
	if (!fd_node)
		return (NULL);
	tmp = "";
	fd_node->rest = ft_buffering(fd, fd_node->rest, tmp);
	if (!fd_node->rest || !*fd_node->rest)
	{
		ft_remove(&fd_list, fd);
		return (NULL);
	}
	line = ft_rest(&fd_node->rest);
	if (!line)
		ft_remove(&fd_list, fd);
	return (line);
}
