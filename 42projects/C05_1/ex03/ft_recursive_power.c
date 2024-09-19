/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:20:38 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/09 12:24:28 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_iterative_power(nb, power - 1));
}

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_power(0,0));
// 	return (0);
// }