/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:58:58 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 12:57:05 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		value = 1;
		while (value < max + 1)
		{
			tab[index / max + 1][index % max + 1] = value;
			if (is_valid_value(tab, value, index, max))
			{
				if (solve_tab(tab, index + 1, size))
					return (1);
			}
			value++;
		}
		tab[index / max + 1][index % max + 1] = 0;
	}
	return (0);
}
