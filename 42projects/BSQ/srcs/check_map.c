/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:11:18 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/18 17:32:03 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ All lines must have the same length.
// ◦ There’s at least one line of at least one box.
// ◦ At each end of line, there’s a line break.
// ◦ The characters on the map can only be those introduced in the first line.
// ◦ The map is invalid if a character is missing 
//from the first line, or if two characters
// (of empty, full and obstacle) are identical.
// ◦ The characters can be any printable character, even numbers.
// ◦ In case of an invalid map, your program should 
// display map error on the error
// output followed by a line break. Your program will then move on to the next
// map

// #include <unistd.h>
// // #include "ft_atoi.c"
// // #include "ft_strlen.c"
// // #include "ft_str_is_printable.c"
// // #include "ft_characters.c"
// // bufffer[0] = lines
// // temp[0] = length of lines
// // temp[1] = also to check length of lines
// // temp[2] = how many lines
// // c[0] = empty
// // c[1] = pbs
// // c[2] = full
// int	length_of_line(char *buffer, char c[3]);
// char *ft_characters(char *buffer);
// int	check_map(char *buffer, int length)
// {
// 	int		i;
// 	int		temp[3];
// 	char	c[3];
// 	char	*ptr = c;
// 	int		lines;
// 	char	*firstline;

// 	i = 0;
//     while (i < 3)
//     {
//         *(ptr + i) = *(ft_characters(buffer) + i);
//         i++;
//     }
// 	firstline = first_
// 	// i = ft_strlen(first_line(buffer));
// 	lines = ft_atoi(first_line(buffer));
// 	temp[0] = length_of_line(buffer,&c[3]);
// 	temp[2] = 0;

// 	if (c[0] == c[1] || c[0] ==c[2] || c[1] == c[2])
// 		return (-1); //check duplicate
// 	while (buffer[i] != '\n')
// 		i++;
// 	if (ft_str_is_printable(first_line(buffer)) == 0)
// 		return (-1);
// 	while (i < length)
// 	{
// 		temp[1] = 0;
// 		while (buffer[i] != '\n')
// 		{
// 			if (buffer[i] != c[0] || buffer[i] != c[1])
// 				return (-1);
// 			i++;
// 			temp[1]++;
// 		}
// 		if (temp[1] != temp[0])
// 			return (-1);
// 		temp[2]++;
// 	}
// 	if (lines != temp[2])
// 			return (-1);
// 	return (1);
// }

// int	length_of_line(char *buffer, char c[3])
// {
// 	int	i;
// 	int	lenline;

// 	lenline = 0;
// 	while (buffer[i] != '\n')
// 	{
// 		if (buffer[i] != c[0] || buffer[i] != c[1])
// 			return (-1);
// 		i++;
// 		lenline++;
// 	}
// 	return (lenline);
// }

// // char *first_line(char *buffer)
// // {
// // 	char	*first_line;

// // 	while (*buffer != '\n')
// // 		first_line++;
// // 	return (first_line);
// // }