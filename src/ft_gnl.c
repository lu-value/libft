/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:18:23 by lm0uta            #+#    #+#             */
/*   Updated: 2025/12/19 14:26:07 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*gnl_strjoin(char *stash, char *buffer)
{
	char	*tmp;
	char	*result;

	if (!stash)
		return (ft_strdup(buffer));
	tmp = ft_strjoin(stash, buffer);
	free(stash);
	if (!tmp)
		return (NULL);
	result = tmp;
	return (result);
}

static char	*extract_line(char *stash)
{
	size_t	len;
	char	*newline;

	if (!stash || !*stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (newline)
		len = newline - stash + 1;
	else
		len = ft_strlen(stash);
	return (ft_substr(stash, 0, len));
}

static char	*update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_strdup(stash + i);
	free(stash);
	return (new_stash);
}

/**
 * ft_gnl - reads a line from file descriptor
 * @fd: file descriptor to read from
 * Return: line read or NULL if EOF/error
 */
char	*ft_gnl(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash), stash = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
