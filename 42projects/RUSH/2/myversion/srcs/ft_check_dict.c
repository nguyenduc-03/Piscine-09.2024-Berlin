/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:04:46 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 13:15:25 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_dict.h"
#include <stdio.h>
#include <fcntl.h>    // for open
#include <unistd.h>   // for read, write, close
#include <stdlib.h>   // for malloc, free

int		ft_is_valid_char(char c);
int		ft_is_valid_num(char c);
ssize_t	ft_how_long_dict(char *filename);
int		is_valid_line(const char *line);

// void	print_buffer(const char *buffer);

int	take_info_from_dict( char *filename, char **buffer,
int filelong)
{
	int		fd;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	*buffer = (char *)malloc(filelong + 1);
	if (!*buffer)
	{
		close(fd);
		return (-1);
	}
	bytes_read = read(fd, *buffer, filelong);
	if (bytes_read != filelong)
	{
		free(*buffer);
		close(fd);
		return (-1);
	}
	(*buffer)[filelong] = '\0';
	close(fd);
	return (1);
}

int	check_lines( char *buffer,
int filelong)
{
	ssize_t	i;
	ssize_t	start;
	int		line_valid;

	i = 0;
	start = 0;
	while (i < filelong)
	{
		while (i < filelong && buffer[i] != '\n')
			i++;
		line_valid = is_valid_line(&buffer[start]);
		if (line_valid != 1)
			return (-1);
		i++;
		start = i;
	}
	if (start < filelong)
	{
		line_valid = is_valid_line(&buffer[start]);
		if (line_valid != 1)
			return (-1);
	}
	return (1);
}

int	ft_check_dict( char *filename)
{
	char	*buffer;
	int		ret;
	int		filelong;

	filelong = ft_how_long_dict(filename);
	ret = take_info_from_dict(filename, &buffer, filelong);
	if (ret == -1)
		return (-1);
	ret = check_lines(buffer, filelong);
	free(buffer);
	return (ret);
}

// int	main(void)
// {
// 	printf("%d\n", ft_check_dict("numbers.dict"));
// 	return (0);
// }
