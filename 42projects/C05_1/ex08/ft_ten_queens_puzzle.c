/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:19:04 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/09 16:43:18 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define N 10

bool	is_safe(int queens[], int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (queens[i] == row || queens[i] - i == row - col 
			|| queens[i] + i == row + col)
			return (false);
		i++;
	}
	return (true);
}

void	print_solution(int queens[])
{
	int	i;

	i = 0;
	while (i < N)
	{
		printf("%d", queens[i]);
		i++;
	}
	printf("\n");
}

void	solve(int queens[], int col, int *count)
{
	int	row;

	if (col == N)
	{
		print_solution(queens);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < N)
	{
		if (is_safe(queens, row, col))
		{
			queens[col] = row;
			solve(queens, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[N];
	int	count;

	count = 0;
	solve(queens, 0, &count);
	return (count);
}

int	main(void)
{
	int	solutions;

	solutions = ft_ten_queens_puzzle();
	return (0);
}
