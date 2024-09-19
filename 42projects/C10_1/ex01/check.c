/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:54:38 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/17 12:57:16 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	int fd = open("nonexistent.txt", O_RDONLY);
if (fd == -1)
    printf("%s\n", strerror(errno));  // Prints a description of the error
return 0;
}