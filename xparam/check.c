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
	uint8_t	row_state;
	int		count;

	vmax = 0;
	row_state = 1;
	i = 1;
	count = tab[0][row];
	while (i < max + 1 && tab[i][row] != 0)
	{
		if (tab[i][row] > vmax)
		{
			vmax = tab[i][row];
			count--;
		}
		i++;
	}
	if (i < max + 1 && tab[i][row] == 0)
		row_state = 0;
	if (row_state == 1 && count != 0)
		return (0);
	else if (row_state == 0 && count < 0)
		return (0);
	return (1);
}

uint8_t	check_row_down(uint8_t **tab, uint8_t row, uint8_t max)
{
	uint8_t	i;
	int		count;
	uint8_t	row_state;
	uint8_t	vmax;

	count = tab[max + 1][row];
	i = max;
	row_state = 1;
	vmax = 0;
	while (i > 0)
	{
		if (tab[i][row] == 0)
			row_state = 0;
		if (tab[i][row] > vmax)
		{
			vmax = tab[i][row];
			count--;
		}
		i--;
	}
	if (row_state == 1 && count != 0)
		return (0);
	return (1);
}

uint8_t	check_line_left(uint8_t **tab, uint8_t line, uint8_t max)
{
	uint8_t	i;
	uint8_t	vmax;
	uint8_t	line_state;
	int		count;

	count = tab[line][0];
	line_state = 1;
	vmax = 0;
	i = 1;
	while (i < max + 1 && tab[line][i] != 0)
	{
		if (tab[line][i] > vmax)
		{
			vmax = tab[line][i];
			count--;
		}
		i++;
	}
	if (i < max + 1 && tab[line][i] == 0)
		line_state = 0;
	if (line_state == 1 && count != 0)
		return (0);
	else if (line_state == 0 && count < 0)
		return (0);
	return (1);
}

uint8_t	check_line_right(uint8_t **tab, uint8_t line, uint8_t max)
{
	uint8_t	i;
	int		count;
	uint8_t	vmax;
	uint8_t	line_state;

	i = max;
	vmax = 0;
	count = tab[line][max + 1];
	line_state = 1;
	while (i > 0)
	{
		if (tab[line][i] == 0)
			line_state = 0;
		if (tab[line][i] > vmax)
		{
			vmax = tab[line][i];
			count--;
		}
		i--;
	}
	if (line_state == 1 && count != 0)
		return (0);
	return (1);
}

uint8_t	check_line(uint8_t **tab, uint8_t line, uint8_t max)
{
	if (check_line_left(tab, line, max) && check_line_right(tab, line, max))
		return (1);
	return (0);
}

uint8_t	check_row(uint8_t **tab, uint8_t row, uint8_t max)
{
	if (check_row_up(tab, row, max) && check_row_down(tab, row, max))
		return (1);
	return (0);
}
//uint8_t	check_row_up(uint8_t **tab, uint8_t row, uint8_t max)
//{
//	uint8_t	i;
//	uint8_t	vmax;
//	uint8_t	count;
//
//	vmax = 0;
//	i = 1;
//	count = tab[0][row];
//	while (i < max + 1)
//	{
//		if (tab[i][row] > vmax)
//		{
//			vmax = tab[i][row];
//			count--;
//		}
//		i++;
//	}
//	if (count != 0)
//		return (0);
//	return (1);
//}
//
//uint8_t	check_row_down(uint8_t **tab, uint8_t row, uint8_t max)
//{
//	uint8_t	i;
//	uint8_t	count;
//	uint8_t	vmax;
//
//	count = tab[max + 1][row];
//	i = max;
//	vmax = 0;
//	while (i > 0)
//	{
//		if (tab[i][row] > vmax)
//		{
//			vmax = tab[i][row];
//			count--;
//		}
//		i--;
//	}
//	if (count != 0)
//		return (0);
//	return (1);
//}
//
//uint8_t	check_line_left(uint8_t **tab, uint8_t line, uint8_t max)
//{
//	uint8_t	i;
//	uint8_t	vmax;
//	uint8_t	count;
//
//	count = tab[line][0];
//	vmax = 0;
//	i = 1;
//	while (i < max + 1)
//	{
//		if (tab[line][i] > vmax)
//		{
//			vmax = tab[line][i];
//			count--;
//		}
//		i++;
//	}
//	if (count != 0)
//		return (0);
//	return (1);
//}
//
//uint8_t	check_line_right(uint8_t **tab, uint8_t line, uint8_t max)
//{
//	uint8_t	i;
//	uint8_t	count;
//	uint8_t	vmax;
//
//	i = max;
//	vmax = 0;
//	count = tab[line][max + 1];
//	while (i > 0)
//	{
//		if (tab[line][i] > vmax)
//		{
//			vmax = tab[line][i];
//			count--;
//		}
//		i--;
//	}
//	if (count != 0)
//		return (0);
//	return (1);
//}

uint8_t	valid_tab(uint8_t **tab, uint8_t max)
{
	uint8_t	i;

	i = 1;
	while (i <= max)
	{
		if (!check_row(tab, i, max) || !check_line(tab, i, max))
			return (0);
		i++;
	}
	return (1);
}
