/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:27:10 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/05 13:00:20 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare_chars(char c1, char c2)
{
	if (c1 < c2)
	{
		return (-1);
	}
	if (c1 > c2)
	{
		return (1);
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (compare_chars(s1[i], s2[i]));
		}
		i++;
	}
	return (0); 
}


#include <stdio.h>
int main() {
    char a[] = "Abc";
    char b[] = "Abcda";
    int result = ft_strncmp(a, b, 2);
    
    // Convert result to a string to write it, because write expects a string
    char result_str[12];
    int length = snprintf(result_str, sizeof(result_str), "%d\n", result);
    write(1, result_str, length);
    
    return 0;
}
