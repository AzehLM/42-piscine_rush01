/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:40:47 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 07:54:11 by gueberso         ###   ########.fr       */
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
			duptab[grid_size][j] = 1;
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
			duptab[i][grid_size] = 1;
		i++;
	}
}

void	max_column_fill(int **tab, int i, int j, int size)
{
	int	fill;

	fill = 1;
	if (i == 0)
	{
		while (i < size)
		{
			if (tab[i + 1][j] == 0)
				tab[i + 1][j] = fill;
			i++;
			fill++;
		}
	}
	else
	{
		while (i > 1)
		{
			if (tab[i - 1][j] == 0)
				tab[i - 1][j] = fill;
			i--;
			fill++;
		}
	}
}

void	max_row_fill(int **tab, int i, int j, int size)
{
	int	fill;

	fill = 1;
	if (j == 0)
	{
		while (j < size)
		{
			if (tab[i][j + 1] == 0)
				tab[i][j + 1] = fill;
			j++;
			fill++;
		}
	}
	else
	{
		while (j > 1)
		{
			if (tab[i][j - 1] == 0)
				tab[i][j - 1] = fill;
			j--;
			fill++;
		}
	}
}

void	fill_max(int **tab, int size)
{
	int	i;
	int	j;

	size /= 8;
	i = -1;
	while (++i < size + 2)
	{
		j = -1;
		if (i == 0 || i == size + 1)
		{
			while (++j < size + 2)
			{
				if (tab[i][j] == size)
					max_column_fill(tab, i, j, size);
			}
		}
		else
		{
			while (++j < size + 2)
			{
				if ((j == 0 || j == size + 1) && tab[i][j] == size)
					max_row_fill(tab, i, j, size);
			}
		}
	}
}
