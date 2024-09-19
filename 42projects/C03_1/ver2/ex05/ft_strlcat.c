/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:42:38 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/05 12:55:12 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int				dest_len;
	unsigned int				i;
	unsigned int				src_len;
	unsigned int				available_space;

	i = 0;
	dest_len = ft_strlen(dest);
	available_space = size - dest_len - 1;
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (src[i] != '\0' && i < available_space)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <string.h>
#include <stdio.h>
int main() {
    char dest[7] = "Hello, ";
     char *src = "world!";
	

    unsigned int size = sizeof(dest) - 2;

    unsigned int result 
		= ft_strlcat(dest, src, size);

    printf("Resulting string: '%s'\n", dest); 
    printf("Total length of 
	the string that would have been created: %u\n", result);

    return 0;
}
*/