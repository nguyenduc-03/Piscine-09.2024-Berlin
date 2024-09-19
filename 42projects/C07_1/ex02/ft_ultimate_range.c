/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:04:33 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/12 11:47:02 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr; 
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	arr = (int *)malloc ((max - min) * sizeof(*arr));
	if (!arr)
	{
		return (-1);
	}
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}

// int	main(void)
// {
// 	int	*range;
// 	int	size;
// 	int	min;
// 	int	max;

// 	max = 1123123;
// 	min = 123213;
// 	size = ft_ultimate_range(&range, min, max);
// 	printf("%d\n", size);
// 	return (0);
// }
