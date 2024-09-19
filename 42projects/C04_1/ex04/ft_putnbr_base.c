/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:23:30 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/06 11:16:12 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h> 
#include <stddef.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	checkvalid( char *str)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = ft_strlen(str);
	if (base_len <= 1)
	{
		return (NULL);
	}
	while (base_len[i] != '\0')
	{
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
}

/* 4 case :
input is a interger(decimal), changing to another base
1. decimal
	check the base = 0..9
		if nbr < 0 then "-" then the same with ft_putnbr.c

2. binary
group of 2 divied by 2
	check the base = 01
		if nbr < 0 then "1" then do from decimal in binar
3. hexi
group of 4 divied by 16
count how many bit binary we need : a number = log2(a number) bit
	check base
		if nbr < 0 then 
						- take the -nbr value (positive)
						- convert to binary ( but we dont know how many bit )
						- 0 become 1, 1 become 0 and add 1 to it
						- convert again to hex

				
4. octal
same thing with hexi ( octal is group of 3 bits)
convert by divied with 8
*/