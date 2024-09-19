/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:39:02 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/11 13:04:12 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr; 
	int	i;

	i = 0;
	arr = (int *)malloc ((max - min) * 4);
	if (!arr)
		return (NULL);
	if (min >= max)
		return (NULL);
	else
	{
		while (min < max)
		{
			arr [i] = min;
			min++;
			i++;
		}
	}
	return (arr);
}

// int	main(void)
// {
// 	int	*range;
// 	int	i;
// 	int	size;
// 	int	a;
// 	int	b;

// 	i = 0;
// 	a = 2;
// 	b = 10;
// 	size = b - a;
// 	range = ft_range(a, b);
// 	if (range)
// 	{
// 		while (i < size)
// 		{
// 			printf("%d\n", range[i]);
// 			i++;
// 		}
// 		free(range);
// 	}
// 	return (0);
// }
