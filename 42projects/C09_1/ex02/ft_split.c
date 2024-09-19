/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:40:46 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/16 15:02:33 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//is_charset: Checks if the character c is in the charset string.
//count_words: Counts the number of words in str
// separated by characters in charset.
//copy_word: Allocates memory and copies len characters from 
//start into a new string word.
// get_word : Extracts a word from str and returns it.
//ft_split : Splits str into an array of words separated by characters 
//in charset.
#include <stdlib.h>

static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
		{
			if (in_word)
				in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		str++;
	}
	return (count);
}

static char	*copy_word(char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	*get_word(char **str, char *charset)
{
	char	*start;
	char	*word;
	int		len;

	while (is_charset(**str, charset))
		(*str)++;
	start = *str;
	len = 0;
	while (**str && !is_charset(**str, charset))
	{
		len++;
		(*str)++;
	}
	if (len == 0)
		return (NULL);
	word = copy_word(start, len);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;
	int		i;

	if (!str || !charset)
		return (NULL);
	word_count = count_words(str, charset);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = get_word(&str, charset);
		if (!result[i])
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// char	**ft_split(char *str, char *charset);

// int	main(void)
// {
// 	char	**result;
// 	char	str[] = "Hello ?world this! is a b test";
// 	char	delim[] = " ?!";

// 	result = ft_split(str, delim);
// 	if (result)
// 	{
// 		char **temp = result;
// 		while (*temp)
// 		{
// 			printf("%s\n", *temp);
// 			free(*temp);
// 			temp++;
// 		}
// 		free(result);
// 	}
// 	return (0);
// }