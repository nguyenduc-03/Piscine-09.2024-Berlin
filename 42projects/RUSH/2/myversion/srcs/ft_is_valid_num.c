/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:45:30 by dagwu             #+#    #+#             */
/*   Updated: 2024/09/15 12:54:56 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is_valid_num.h"

int	ft_is_valid_num(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (1);
}

// #include <stdio.h>

// int	ft_is_valid_num(char c);

// int	main(void)
// {
// 	char test_chars[] = {'0', '5', '9', 'a', '@', ' ', '1'};
// 	int i;

// 	for (i = 0; i < sizeof(test_chars); i++)
// 	{
// 		char c = test_chars[i];
// 		printf("Character '%c' is %s\n", c, ft_
//is_valid_num(c) == 1 ? "valid" : "invalid");
// 	}

// 	return 0;
// }