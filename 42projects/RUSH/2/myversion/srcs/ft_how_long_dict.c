/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_long_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:44:23 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 12:55:06 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_how_long_dict.h"

ssize_t	ft_how_long_dict(char *filename)
{
	int		fd;
	char	buffer[128];
	ssize_t	bytes_read;
	ssize_t	total_bytes;

	total_bytes = 0;
	bytes_read = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			close(fd);
			return (-1);
		}
		total_bytes += bytes_read;
	}
	close(fd);
	return (total_bytes);
}

// int	main(void)
// {
// 	ssize_t size = ft_how_long_dict("numbers.dict");
// 	char buf[50];
// 	printf("%zd\n", size);
// 	int len = snprintf(buf, sizeof(buf), "File size: %zd bytes\n", size);
// 	write(1, buf, len);
// 	return (0);
// }

//works