/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:49:50 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/28 18:05:56 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *buffer, char *buf)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!buffer && !buf)
		return (NULL);
	if (buffer)
		s1_len = ft_strlen(buffer);
	else
		s1_len = 0;
	if (buf)
		s2_len = ft_strlen(buf);
	else
		s2_len = 0;
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	if (buffer)
		ft_memcpy(result, buffer, s1_len);
	if (buf)
		ft_memcpy(result + s1_len, buf, s2_len);
	result[s1_len + s2_len] = '\0';
	free(buffer);
	return (result);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*result;
	int		byte_read;

	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, result, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		result[byte_read] = '\0';
		buffer = ft_free(buffer, result);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(result);
	return (buffer);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next(buffer);
	return (line);
}
