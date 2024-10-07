/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:57:59 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 12:57:24 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_row_up(int **tab, int row, int max)
{
	int	i;
	int	vmax;
	int	count;

	vmax = 0;
	i = 1;
	count = tab[0][row];
	while (i < max + 1)
	{
		if (tab[i][row] > vmax)
		{
			vmax = tab[i][row];
			count--;
		}
		i++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_row_down(int **tab, int row, int max)
{
	int	i;
	int	count;
	int	vmax;

	count = tab[max + 1][row];
	i = max;
	vmax = 0;
	while (i > 0)
	{
		if (tab[i][row] > vmax)
		{
			vmax = tab[i][row];
			count--;
		}
		i--;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_line_left(int **tab, int line, int max)
{
	int	i;
	int	vmax;
	int	count;

	count = tab[line][0];
	vmax = 0;
	i = 1;
	while (i < max + 1)
	{
		if (tab[line][i] > vmax)
		{
			vmax = tab[line][i];
			count--;
		}
		i++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_line_right(int **tab, int line, int max)
{
	int	i;
	int	count;
	int	vmax;

	i = max;
	vmax = 0;
	count = tab[line][max + 1];
	while (i > 0)
	{
		if (tab[line][i] > vmax)
		{
			vmax = tab[line][i];
			count--;
		}
		i--;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	valid_tab(int **tab, int max)
{
	int	i;

	i = 1;
	while (i <= max)
	{
		if (!check_row_up(tab, i, max) || !check_row_down(tab, i, max)
			|| !check_line_left(tab, i, max) || !check_line_right(tab, i, max))
			return (0);
		i++;
	}
	return (1);
}
