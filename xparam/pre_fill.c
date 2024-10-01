/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:53 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/01 18:31:17 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_up_down(int **duptab, int size)
{
	int	i;
	int	j;
	int	grid_size;

	grid_size = size / 8;
	j = 1;
	i = 0;
	while (j <= grid_size)
	{
		if (duptab[0][j] == 1 && check_value(duptab, i + 1, j) == 1)
			duptab[1][j] = grid_size;
		if (duptab[grid_size + 1][j] == 1
			&& check_value(duptab, grid_size, j) == 1)
			duptab[grid_size][j] = grid_size;
		j++;
	}
}

void	fill_left_right(int **duptab, int size)
{
	int	i;
	int	grid_size;

	grid_size = size / 8;
	i = 1;
	while (i <= grid_size)
	{
		if (duptab[i][0] == 1 && check_value(duptab, i, 1) == 1)
			duptab[i][1] = grid_size;
		if (duptab[i][grid_size + 1] == 1
			&& check_value(duptab, i, grid_size) == 1)
			duptab[i][grid_size] = grid_size;
		i++;
	}
}

void	fill_min(int **duptab, int size)
{
	fill_left_right(duptab, size);
	fill_up_down(duptab, size);
}

// void	ft_prefill(int **tab, int size)
// {
//     int    min;
//     int    i;
//     int    j;

//     i = 0;
//     j = 0;
//     min = 1;
//     size = size / 8;
//     while (i < size + 2)
//     {
//         if (i == 0 || i == size + 1)
//         {
//         	while (j < size + 2)
//             {
//                 if (tab[i][j] == size)
//                     fill(tab, i, j);
//                 j++;
//             }
//         }
//         else
//         {
//             j = 0;
//             if (tab[i][j] == size)
//                 fill(tab, i, j);
//             j = size + 1;
//             if (tab[i][j] == size)
//                 fill (tab, i, j);
//             return (-1);
//         }
//         i++;
//     }
// }
