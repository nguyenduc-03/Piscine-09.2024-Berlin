/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:24:31 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/18 17:56:09 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/my_functions.h"

int	main(int argc, char **argv)
{
	argc = argc + 1 - 1;
	display_map(argv[1]);
	return (0);
}

// #include "../include/my_functions.h"
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	if (argc == 1)
// 	{
// 		write(2, "File name missing.\n", 19);
// 		return (1);
// 	}
// 	// if (argc > 2)
// 	// {
// 	// 	write(2, "Too many arguments.\n", 20);
// 	// 	return (1);
// 	// }
// 	while (i < argc)
// 	{
// 		display_map(argv[i]);
// 	}

// 	return (0);
// }
