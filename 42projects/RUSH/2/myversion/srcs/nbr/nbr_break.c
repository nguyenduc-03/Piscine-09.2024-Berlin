/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:38:42 by mamu              #+#    #+#             */
/*   Updated: 2024/09/15 14:21:12 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include "nbr.h"

void	nbr_buffer_add(t_nbr_buffer *buffer, char *word)
{
	char	**words;
	int		i;

	words = malloc(sizeof(char *) * (buffer->size + 1));
	i = 0;
	while (i < buffer->size)
	{
		words[i] = buffer->words[i];
		i++;
	}
	words[i] = word;
	free(buffer->words);
	buffer->words = words;
	buffer->size += 1;
}

static int	nbr_store(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	char	*word;

	word = dict_get(dict, str);
	if (!word)
		return (-1);
	nbr_buffer_add(buffer, word);
	return (0);
}

char	*dict_get(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(key, dict->keys[i]) == 0)
			return (dict->values[i]);
		i++;
	}
	return (0);
}

static int	nbr_print_tens(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_store(buffer, dict, nbr_substr(str, 0, 0)));
	if (str[0] == '1')
		return (nbr_store(buffer, dict, str));
	if (nbr_store(buffer, dict, nbr_pad_zero(str[0], 1)) == -1)
		return (-1);
	if (str[1] != '0')
		return (nbr_store(buffer, dict, nbr_substr(str, 1, 1)));
	return (0);
}

static int	nbr_print_hundreds(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		return (nbr_store(buffer, dict, "0"));
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_store(buffer, dict, str));
	if (len == 2)
		return (nbr_print_tens(buffer, dict, nbr_substr(str, 0, 1)));
	if (nbr_store(buffer, dict, nbr_substr(str, 0, 0)) == -1)
		return (-1);
	if (nbr_store(buffer, dict, "100") == -1)
		return (-1);
	if (nbr_print_tens(buffer, dict, nbr_substr(str, 1, 2)) == -1)
		return (-1);
	return (0);
}

int	nbr_break(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int				i;
	int				n;
	int				remain;
	char			*digits;

	i = 0;
	remain = ft_strlen(str);
	while (i < ft_strlen(str))
	{
		n = remain % 3;
		if (n == 0)
			n = 3;
		digits = nbr_substr(str, i, i + n - 1);
		if (nbr_print_hundreds(buffer, dict, digits) == -1)
			return (-1);
		if (remain - n >= 3
			&& !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
			if (nbr_store(buffer, dict, nbr_pad_zero('1', remain - n)) == -1)
				return (-1);
		i += n;
		remain -= n;
	}
	return (0);
}

char	*nbr_substr(char *str, int from, int to)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = to - from + 1;
	s = malloc(len + 1);
	while (i < len)
	{
		s[i] = str[from + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*nbr_pad_zero(char c, int zeros)
{
	char	*p;
	int		i;
	int		len;

	len = 1 + zeros;
	p = malloc(len + 1);
	p[0] = c;
	i = 1;
	while (i < len)
	{
		p[i] = '0';
		i++;
	}
	p[i] = '\0';
	return (p);
}
void	nbr_buffer_print(t_nbr_buffer *buffer)
{
	int	i;

	i = 0;
	while (i < buffer->size)
	{
		ft_putstr(buffer->words[i]);
		if (i < buffer->size - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
