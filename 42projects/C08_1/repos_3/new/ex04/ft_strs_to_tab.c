/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:49:02 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/16 14:14:29 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *str, int size)
{
	char	*array;
	int		i;

	array = malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		array[i] = str[i];
		i += 1;
	}
	array[i] = '\0';
	return (array);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*array;

	array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strcpy(av[i], array[i].size);
		i++;
	}
	array[i].size = 0;
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	*strings[] = {"Hello", "World", "42", "Berlin"};
// 	t_stock_str	*result;
// 	int		ac = 4;
// 	int		i;

// 	result = ft_strs_to_tab(ac, strings);
// 	if (result == NULL)
// 	{
// 		printf("Error: Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < ac)
// 	{
// 		printf("Original: %s, Copy: %s, 
// Length: %d\n", result[i].str, result[i].copy, result[i].size);
// 		i++;
// 	}
// 	// ft_free_tab(result, ac);
// 	return (0);
// }
