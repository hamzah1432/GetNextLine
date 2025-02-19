/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:40:03 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/19 17:35:27 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static char	*set_line(char *line_buffer, char (*rem)[BUFFER_SIZE + 1])
{
	size_t	i;
	char	*result;

	i = 0;
	if (!line_buffer[0])
	{
		free(line_buffer);
		return (NULL);
	}
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	result = ft_substr(line_buffer, 0, i);
	ft_strlcpy(*rem, &line_buffer[i], BUFFER_SIZE);
	free(line_buffer);
	return (result);
}

static char	*fill_line(char rem[], int fd)
{
	int		bytes_read;
	char	*line;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(rem);
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	rem[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line(rem, fd);
	if (!line)
		return (NULL);
	return (set_line(line, &rem));
}

// #include <stdio.h>
// int main ()
// {
// 	char *line;
// 	int fd =  open("src/text.txt", O_RDONLY);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 	// line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	}

// 	close(fd);
// 	return(0);
// }