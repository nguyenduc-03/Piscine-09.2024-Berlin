/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:59:15 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/16 12:42:22 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0' ;
	write(1, &digit, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		i++;
	}
}
// struct s_stock_str	*ft_strs_to_tab(
//int ac, char **av);  // Declare function prototypes
// void				ft_show_tab(struct s_stock_str *par);
// void	ft_free_tab(t_stock_str *tab, int size);
// #include <stdio.h>

// int	main(void)
// {
// 	char	*strings[] = {"Hello", "World", "42", "Berlin"};
// 	int		ac;

// 	ac = 4;
// 	t_stock_str *tab = ft_strs_to_tab(ac, strings);
// 	if (tab == NULL)
// 	{
// 		printf("Error: Memory allocation failed\n");
// 		return (1);
// 	}
// 	ft_show_tab(tab);
// 	ft_free_tab(tab, ac);
// 	return (0);
// }
