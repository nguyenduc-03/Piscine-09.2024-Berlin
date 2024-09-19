// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/14 15:42:52 by ducnguye          #+#    #+#             */
// /*   Updated: 2024/09/14 15:42:55 by ducnguye         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <errno.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main()
// {
// 	char	*buffer = (char *)malloc(5);
// 	int fd = open("number.digit", O_RDONLY);
// 	ssize_t	bytes_read = read(fd, buffer, );
// 	buffer[bytes_read] = '\0';
// 	printf("File content:\n %s\n", buffer);
// 	free(buffer);
// 	close(fd);
// 	return 0;
// }