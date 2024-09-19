/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:31:38 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/18 17:39:51 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_characters(char *buffer)
{
	char		*start;
	static char	last_three[4];
	char		*first_line;

	start = buffer;
	first_line = buffer;
	while (*first_line != '\n' && *first_line != '\0')
		first_line++;
	start = first_line - 3;
	last_three[0] = start[0];
	last_three[1] = start[1];
	last_three[2] = start[2];
	last_three[3] = '\0';
	return (last_three);
}
