/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:51:19 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/09 16:55:52 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	if (nb < 0)
		return (0);
	i = 1;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}

// #include<stdio.h>
// int main()

// {
// 	printf("%d\n",ft_iterative_factorial(2));
// 	return 0;
// }