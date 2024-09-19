/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:06:37 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/04 16:41:45 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // For NULL

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

char	*ft_strstr(char *str, char *to_find)
{
	const char	*haystack;
	const char	*needle;

	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	while (*str != '\0')
	{
		haystack = str;
		needle = to_find;
		while (*needle != '\0' && *haystack == *needle)
		{
			haystack++;
			needle++;
		}
		if (*needle == '\0')
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/*
#include <stdio.h> 
int main(void)
{
    char haystack[] = "Hello, world!";
    char needle1[] = "world";
    char needle2[] = "Hello";
    char needle3[] = "foo";

    char *result;

    result = ft_strstr(haystack, needle1);
    if (result)
        printf("Found '%s' in '%s': %s\n", needle1, haystack, result);
    else
        printf("'%s' not found in '%s'\n", needle1, haystack);

    result = ft_strstr(haystack, needle2);
    if (result)
        printf("Found '%s' in '%s': %s\n", needle2, haystack, result);
    else
        printf("'%s' not found in '%s'\n", needle2, haystack);

    result = ft_strstr(haystack, needle3);
    if (result)
        printf("Found '%s' in '%s': %s\n", needle3, haystack, result);
    else
        printf("'%s' not found in '%s'\n", needle3, haystack);

    return 0;
}
*/