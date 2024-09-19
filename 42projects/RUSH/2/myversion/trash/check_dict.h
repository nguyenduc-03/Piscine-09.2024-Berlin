/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:47:31 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 12:50:02 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_DICT_H
# define CHECK_DICT_H

# include <stdio.h>

int		ft_check_dict(char *filename);
int		ft_is_valid_char(char c);
int		ft_is_valid_num(char c);
ssize_t	ft_how_long_dict(char *filename);
int		is_valid_line(const char *line);

#endif // CHECK_DICT_H
