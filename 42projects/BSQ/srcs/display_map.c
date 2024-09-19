/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:48:20 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/18 17:56:22 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>    // for open
#include <stdlib.h>
#include "../include/my_functions.h"

// #include "check_map.c"

#define BUFFER_SIZE 128

ssize_t	ft_how_long_dict(char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	total_bytes;

	total_bytes = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			return (-1);
		}
		if (bytes_read == 0)
			break ;
		total_bytes += bytes_read;
	}
	close(fd);
	return (total_bytes);
}

void	display_file_content(int fd, ssize_t length)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	total_read;

	total_read = 0;
	while (total_read < length)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			write(2, "Cannot read file.\n", 19);
			return ;
		}
		if (bytes_read == 0)
			break ;
		write(1, buffer, bytes_read);
		total_read += bytes_read;
	}
	write(1, "\n", 1);
}

char	*ft_read_file_content(int fd, ssize_t length)
{
	char	*buffer;
	ssize_t	bytes_read;
	ssize_t	total_read;
	ssize_t	i;

	buffer = malloc(length);
	if (!buffer)
		return (NULL);
	total_read = 0;
	i = 0;
	while (total_read < length)
	{
		bytes_read = read(fd, buffer + i, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			write(2, "Cannot read file.\n", 19);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		i += bytes_read;
		total_read += bytes_read;
	}
	return (buffer);
}

void	display_map(const char *filename)
{
	int		fd;
	ssize_t	length;
	char	*content;

	length = ft_how_long_dict((char *)filename);
	if (length < 0)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return ;
	}
	display_file_content(fd, length);
	fd = open(filename, O_RDONLY);
	content = ft_read_file_content(fd, length);
	write(1, "\n", 1);
	ft_putstr(ft_characters(content));
	ft_putstr(first_line(content));
	if (content[0] == 48)
		write(2, "map error\n", 10);
	close(fd);
}

// int	main(void)
// {
// 	display_map("map1");
// 	return (0);
// }
