/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:15:47 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/18 17:52:31 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FUNCTIONS_H
# define MY_FUNCTIONS_H

# include <unistd.h>

ssize_t	ft_how_long_dict(char *filename);
void	display_file_content(int fd, ssize_t length);
void	display_map(const char *filename);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
char	*ft_characters(char *buffer);
char	*first_line(char *buffer);

#endif