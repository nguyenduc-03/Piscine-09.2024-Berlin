/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:03:39 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 14:07:53 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>

int	check_arg(int argc, char **argv, char *default_dict)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
		if (!ft_is_valid_num(argv[1]))
			return (0);
	if (argc == 3)
		if (!ft_is_valid_num(argv[2]))
			return (0);
	return (1);
}
