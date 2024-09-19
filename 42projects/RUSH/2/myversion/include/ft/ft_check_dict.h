/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:52:05 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/15 13:18:45 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_DICT_H
# define FT_CHECK_DICT_H
# include <stdio.h>

int		ft_check_dict(char *filename);
int		ft_is_valid_char(char c);
int		ft_is_valid_num(char c);
ssize_t	ft_how_long_dict(char *filename);
int		is_valid_line(const char *line);

#endif // FT_CHECK_DICT_H
