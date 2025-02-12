/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:42:02 by yomoumen          #+#    #+#             */
/*   Updated: 2024/12/13 15:42:04 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_alloc(int total_len, int byte_read, char *buffer, char *temp)
{
	int		i;
	int		j;
	char	*new_buffer;

	new_buffer = malloc(total_len + byte_read + 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	j = 0;
	while (temp[j])
		new_buffer[i++] = temp[j++];
	new_buffer[i] = '\0';
	free(buffer);
	free(temp);
	return (new_buffer);
}

char	*extract_line(char *buffer, int line_length)
{
	char	*line;
	int		j;

	line = malloc(line_length + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < line_length)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[line_length] == '\n')
	{
		line[j++] = '\n';
	}
	line[j] = '\0';
	return (line);
}

char	*ft_get_line(char **buffer)
{
	char	*line;
	char	*rest;
	int		i;

	if (!*buffer || !**buffer)
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = extract_line(*buffer, i);
	if (!line)
		return (NULL);
	if ((*buffer)[i] == '\n')
		i++;
	rest = ft_strdup((*buffer) + i);
	free(*buffer);
	*buffer = rest;
	return (line);
}

char	*buff_realloc(char *buffer, int fd)
{
	int		byte_read;
	int		total_len;
	char	*temp;

	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	total_len = ft_strlen(buffer);
	byte_read = read(fd, temp, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(temp);
		return (NULL);
	}
	temp[byte_read] = '\0';
	return (ft_alloc(total_len, byte_read, buffer, temp));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	while (!check_new_line(buffer))
	{
		temp = buff_realloc(buffer, fd);
		if (!temp)
		{
			return (ft_check(&buffer, line));
		}
		buffer = temp;
	}
	line = ft_get_line(&buffer);
	return (line);
}
