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

uint8_t	check_row_up(uint8_t **tab, uint8_t row, uint8_t max)
{
	uint8_t	i;
	uint8_t	vmax;
	uint8_t	count;

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

uint8_t	check_row_down(uint8_t **tab, uint8_t row, uint8_t max)
{
	uint8_t	i;
	uint8_t	count;
	uint8_t	vmax;

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

uint8_t	check_line_left(uint8_t **tab, uint8_t line, uint8_t max)
{
	uint8_t	i;
	uint8_t	vmax;
	uint8_t	count;

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

uint8_t	check_line_right(uint8_t **tab, uint8_t line, uint8_t max)
{
	uint8_t	i;
	uint8_t	count;
	uint8_t	vmax;

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

uint8_t	valid_tab(uint8_t **tab, uint8_t max)
{
	uint8_t	i;

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
