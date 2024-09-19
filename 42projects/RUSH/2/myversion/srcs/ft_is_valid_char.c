/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:05:03 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 12:54:49 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is_valid_char.h"

int	ft_is_valid_char(char c)
{
	if (c < 32 || c > 126)
		return (-1);
	return (1);
}

// #include <stdio.h>

// int	ft_is_valid_char(char c);

// int	main(void)
// {
// 	char test_chars[] = {31, 32, 33, 12
//6, 127}; // includes non-printable, printable, and non-printable
// 	int i;

// 	for (i = 0; i < sizeof(test_chars); i++)
// 	{
// 		char c = test_chars[i];
// 		printf("Character %d is %s\n", c,
// ft_is_valid_char(c) == 1 ? "valid" : "invalid");
// 	}

// 	return 0;
// }
