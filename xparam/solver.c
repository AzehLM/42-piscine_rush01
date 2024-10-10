/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:58:58 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 23:40:57 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	new_index(uint8_t index, uint8_t size)
{
	uint8_t	x;
	uint8_t	y;

	if (index == size * size - 1)
		return (size * size);
	x = index / size + 1;
	y = index % size + 1;
	if (y == size)
	{
		y = x;
		x++;
	}
	else if (x == size)
	{
		x = y + 1;
		y++;
	}
	else if (y >= x)
		y++;
	else
		x++;
	return ((x * (size) + y) - (size + 1));
}

uint8_t	solve_tab(uint8_t **tab, uint8_t index, uint8_t size)
{
	uint8_t	value;
	uint8_t	grid_size;
	uint8_t	max;

	max = (size / 8);
	grid_size = max * max;
	if (index == grid_size && valid_tab(tab, max))
		return (1);
	if (index < grid_size)
	{
		if (tab[index / max + 1][index % max + 1] != 0)
		{
			if (solve_tab(tab, new_index(index, max), size))
				return (1);
		}
		else
		{
			value = 1;
			while (value < max + 1)
			{
				tab[index / max + 1][index % max + 1] = value;
				if (is_valid_value(tab, index, max))
				{
					if (solve_tab(tab, new_index(index, max), size))
						return (1);
				}
				value++;
			}
			tab[index / max + 1][index % max + 1] = 0;
		}
	}
	return (0);
}
