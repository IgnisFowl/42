/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:49:50 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2024/11/28 18:06:07 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffers[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
	{
		if (fd >= 0 && fd < OPEN_MAX)
			free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	buffers[fd] = ft_read(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = ft_line(buffers[fd]);
	if (!line)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	buffers[fd] = ft_next(buffers[fd]);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd1 = open("1char.txt", O_RDONLY);
    int fd2 = open("1char.txt", O_RDONLY);
    int fd3 = open("multiple_nl.txt", O_RDONLY);

    char *line;

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    printf("Reading from multiple file descriptors:\n");
    // Read alternately from the file descriptors
    for (int i = 0; i < 10; i++) // Adjust iteration count as needed
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("FD1: %s", line);
			printf("\n");
            free(line);
        }
        line = get_next_line(fd2);
        if (line)
        {
            printf("FD2: %s", line);
			printf("\n");
            free(line);
        }
        line = get_next_line(fd3);
        if (line)
        {
            printf("FD3: %s", line);
			printf("\n");
            free(line);
        }
    }

    // Close the file descriptors
    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}*/