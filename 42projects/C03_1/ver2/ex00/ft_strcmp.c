/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:48:46 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/04 16:50:53 by ducnguye         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0') 
	{
		if (s1[i] < s2[i]) 
		{
			return (-1);
		}
		if (s1[i] > s2[i]) 
		{
			return (1);
		}
		i++;
	}
	return (compare_chars(s1[i], s2[i]));
}

/*#include <stdio.h>
int main() {
    char a[] = "abc";
    char b[] = "Acb";
    int result = ft_strcmp(a, b);
    
    Convert result to a str
	ing to write it, because write expects a string
    char result_str[12];
    int length = snprintf(res
	ult_str, sizeof(result_str), "%d\n", result);
    write(1, result_str, length);
    
    return 0;
*/