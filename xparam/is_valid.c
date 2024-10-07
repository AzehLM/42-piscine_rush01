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

int	check_left(int **tab, int value, int index, int max)
{
	while (index % max != 0)
	{
		index--;
		if (tab[index / max + 1][index % max + 1] == value)
			return (0);
	}
	return (1);
}

int	check_up(int **tab, int value, int index, int max)
{
	while (index / max != 0)
	{
		index -= max;
		if (tab[index / max + 1][index % max + 1] == value)
			return (0);
	}
	return (1);
}


int	is_valid_value(int **tab, int value, int index, int max)
{
	if (!check_left(tab, value, index, max) || !check_up(tab, value, index, max))
		return (0);
	return (1);
}
