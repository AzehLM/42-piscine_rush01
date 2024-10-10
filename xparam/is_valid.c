/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:40 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/07 08:11:30 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	check_left(uint8_t **tab, uint8_t index, uint8_t max)
{
	uint8_t	tempindex;
	uint8_t	value;

	value = tab[index / max + 1][index % max + 1];
	tempindex = index;
	while (index % max != 0)
	{
		index--;
		if (tab[index / max + 1][index % max + 1] == value)
			return (0);
	}
	while (tempindex % max != max - 1)
	{
		tempindex++;
		if (tab[tempindex / max + 1][tempindex % max + 1] == value)
			return (0);
	}
	return (1);
}

uint8_t	check_up(uint8_t **tab, uint8_t index, uint8_t max)
{
	uint8_t	tempindex;
	uint8_t	value;

	value = tab[index / max + 1][index % max + 1];
	tempindex = index;
	while (tempindex / max != 0)
	{
		tempindex -= max;
		if (tab[tempindex / max + 1][tempindex % max + 1] == value)
			return (0);
	}
	while (index / max != max - 1)
	{
		index += max;
		if (tab[index / max + 1][index % max + 1] == value)
			return (0);
	}
	return (1);
}

uint8_t	is_valid_value(uint8_t **tab, uint8_t index, uint8_t max)
{
	if (!check_left(tab, index, max) || !check_up(tab, index, max) || !check_row(tab, index % max + 1, max) || !check_line(tab, index / max + 1, max))
		return (0);
	return (1);
}
