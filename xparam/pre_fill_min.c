/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:40:53 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 07:52:46 by gueberso         ###   ########.fr       */
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

void	min_column_fill(int **tab, int i, int j, int size)
{
	if (i == 0)
	{
		if (tab[i + 1][j] == 0)
			tab[i + 1][j] = size;
	}
	else
	{
		if (tab [i - 1][j] == 0)
			tab[i - 1][j] = size;
	}
	return ;
}

void	min_row_fill(int **tab, int i, int j, int size)
{
	if (j == 0)
	{
		if (tab[i][j + 1] == 0)
			tab[i][j + 1] = size;
	}
	else
	{
		if (tab[i][j - 1] == 0)
			tab[i][j - 1] = size;
	}
	return ;
}

void	fill_min(int **tab, int size)
{
	int	i;
	int	j;

	i = -1;
	size /= 8;
	while (++i < size + 2)
	{
		j = -1;
		if (i == 0 || i == size + 1)
		{
			while (++j < size + 2)
			{
				if (tab[i][j] == 1)
					min_column_fill(tab, i, j, size);
			}
		}
		else
		{
			while (++j < size + 2)
			{
				if (tab[i][j] == 1 && (j == 0 || j == size + 1))
					min_row_fill(tab, i, j, size);
			}
		}
	}
}
