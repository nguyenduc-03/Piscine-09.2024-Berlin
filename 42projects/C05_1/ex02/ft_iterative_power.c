/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:46 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/09 16:59:18 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	answer;

	answer = 1;
	if (power < 0)
		return (0);
	while (power != 0)
	{
		answer = answer * nb;
		power--;
	}
	return (answer);
}

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_power(3, 0));
// 	return (0);
// }