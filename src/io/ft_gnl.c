/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:18:23 by lm0uta            #+#    #+#             */
/*   Updated: 2026/03/04 11:18:02 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

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
		len = (size_t)(newline - stash) + 1;
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

char	*ft_gnl(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*buffer;
	ssize_t		bytes;
	char		*line;
	char		*current_stash;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	current_stash = stash[fd];
	while (!current_stash || !ft_strchr(current_stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(current_stash);
			stash[fd] = NULL;
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		current_stash = gnl_strjoin(current_stash, buffer);
		if (!current_stash)
		{
			free(buffer);
			stash[fd] = NULL;
			return (NULL);
		}
	}
	line = extract_line(current_stash);
	stash[fd] = update_stash(current_stash);
	free(buffer);
	return (line);
}
