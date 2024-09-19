/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:38:54 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 13:08:04 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_valid_line.h"

int	ft_is_valid_char(char c);
int	ft_is_valid_num(char c);

int	is_valid_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_valid_num(line[i]) == 1)
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (-1);
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i] && ft_is_valid_char(line[i]) == 1 && line[i] != '\n')
		i++;
	if (line[i] != 10 && line[i] != '\0')
		return (-1);
	return (1);
}
