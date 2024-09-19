/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:43:36 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 13:17:50 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_check_dict.h"

int	main(int argc, char *argv[])
{
	char	*filename;

	filename = "numbers.dict";
	if (argc > 3)
		return (-1);
	if (argc == 3)
		filename = argv[1];
	if (ft_check_dict(filename) == -1)
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	else
		printf("Dictionary pass.\n");
	return (0);
}
