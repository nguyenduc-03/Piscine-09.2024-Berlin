/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:30:02 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/11 15:34:05 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	calculate_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;
	int	j;

	total_len = 0;
	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total_len++;
			j++;
		}
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;
	int		length;

	length = calculate_length(size, strs, sep);
	s = (char *)malloc(length + 1);
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			s[c++] = sep[j++];
		i++;
	}
	s[c] = '\0';
	return (s);
}

// int	main(void)
// {
// 	char	*tab[4];

// 	tab[0] = "aasdasdasdasdasdasdasdsa";
// 	tab[1] = "b";
// 	tab[2] = "c";
// 	tab[3] = "da";
// 	printf("%s", ft_strjoin(3, tab, " SEP "));
// 	return (0);
// }
