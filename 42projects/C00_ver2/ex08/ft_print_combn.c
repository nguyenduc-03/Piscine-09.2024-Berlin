/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:31:51 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/02 18:32:03 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_combination(int *comb, int n, int is_last) {
    for (int i = 0; i < n; i++) {
        char c = comb[i] + '0'; // Convert integer to character
        write(1, &c, 1);
    }
    if (!is_last) {
        write(1, ", ", 2); // Print comma and space
    }
}

void generate_combinations(int *comb, int start, int n, int current, int total_combinations, int *counter) {
    if (current == n) {
        print_combination(comb, n, *counter == total_combinations - 1);
        (*counter)++;
        return;
    }

    for (int i = start; i <= 10 - n + current; i++) {
        comb[current] = i;
        generate_combinations(comb, i + 1, n, current + 1, total_combinations, counter);
    }
}

void ft_print_combn(int n) {
    if (n <= 0 || n >= 10) return; // Handle invalid input

    // Determine the total number of combinations
    int total_combinations = 1;
    for (int i = 0; i < n; i++) {
        total_combinations *= (10 - i);
        total_combinations /= (i + 1);
    }

    int comb[n]; // Array to store the current combination
    int counter = 0;
    generate_combinations(comb, 0, n, 0, total_combinations, &counter);
}

int main()
{
    ft_print_combn(2);
    return 0;
}