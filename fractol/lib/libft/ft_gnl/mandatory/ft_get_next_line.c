/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:45:28 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 11:52:52 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

static char		*get_line(char **acc);
static ssize_t	load_acc(char **acc, int fd);
static char		*last_line(char **acc);
char			*ft_get_next_line(int fd);

char	*ft_get_next_line(int fd)
{
	static char		*acc;
	ssize_t			bytes;

	if (ft_strchr(acc, '\n'))
		return (get_line(&acc));
	bytes = load_acc(&acc, fd);
	if (bytes == -1)
	{
		free(acc);
		acc = NULL;
		return (NULL);
	}
	if (bytes == 0)
		return (last_line(&acc));
	return (get_line(&acc));
}

static char	*get_line(char **acc)
{
	char	*line;
	char	*next_line;

	next_line = ft_strchr(*acc, '\n') + 1;
	line = ft_substr(*acc, 0, next_line - *acc);
	next_line = ft_strdup(next_line);
	free(*acc);
	if (line == NULL || next_line == NULL)
	{
		free(line);
		free(next_line);
		return (NULL);
	}
	*acc = next_line;
	return (line);
}

static ssize_t	load_acc(char **acc, int fd)
{
	ssize_t	bytes;
	char	*tmp;
	char	*buffer;

	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (-1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || bytes == 0)
			return (free(buffer), bytes);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(*acc, buffer);
		if (!tmp)
			return (free(buffer), bytes);
		free(*acc);
		*acc = tmp;
		if (ft_strchr(buffer, '\n'))
			return (free(buffer), bytes);
		free(buffer);
	}
}

static char	*last_line(char **acc)
{
	char	*line;

	if (*acc && **acc != '\0')
		line = ft_strdup(*acc);
	else
		line = NULL;
	free(*acc);
	*acc = NULL;
	return (line);
}
