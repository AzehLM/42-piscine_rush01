/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:40:47 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/01 19:32:44 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_up_down_max(int **duptab, int size)
{
	int	i;
	int	j;
	int	grid_size;

	grid_size = size / 8;
	j = 1;
	i = 0;
	while (j <= grid_size)
	{
		if (duptab[0][j] == grid_size && check_value(duptab, i + 1, j) == 1)
			duptab[1][j] = 1;
		if (duptab[grid_size + 1][j] == grid_size
			&& check_value(duptab, grid_size, j) == 1)
			duptab[grid_size - 1][j] = 1;
		j++;
	}
}

void	fill_left_right_max(int **duptab, int size)
{
	int	i;
	int	grid_size;

	grid_size = size / 8;
	i = 1;
	while (i <= grid_size)
	{
		if (duptab[i][0] == grid_size && check_value(duptab, i, 1) == 1)
			duptab[i][1] = 1;
		if (duptab[i][grid_size + 1] == grid_size
			&& check_value(duptab, i, grid_size) == 1)
			duptab[i][grid_size - 1] = 1;
		i++;
	}
}

void	fill_max(int **duptab, int size)
{
	fill_left_right_max(duptab, size);
	fill_up_down_max(duptab, size);
}
