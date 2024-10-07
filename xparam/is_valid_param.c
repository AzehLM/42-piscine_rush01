/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:24:11 by azeh              #+#    #+#             */
/*   Updated: 2024/10/01 18:30:21 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	check_n_number(char *str, uint8_t size)
{
	uint8_t	i;
	uint8_t	count;
	uint8_t	grid_size;

	grid_size = (size / 8);
	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] - 48 == grid_size)
			count++;
		i++;
	}
	if (count > grid_size)
		return (0);
	return (1);
}

uint8_t	check_oppos(char *str, uint8_t size)
{
	uint8_t	i;
	uint8_t	j;
	uint8_t	grid_size;
	uint8_t	gridouble;

	i = 0;
	j = 0;
	grid_size = (size / 8);
	gridouble = grid_size * 2;
	while (str && str[i] && j != gridouble)
	{
		if (i == gridouble)
			i = i + gridouble;
		if (((str[i] - 48) + (str[i + gridouble]) - 48) < 3
			|| ((str[i] - 48) + (str[i + gridouble]) - 48) > (grid_size + 1))
			return (0);
		i += 2;
		j++;
	}
	return (1);
}

uint8_t	is_valid_param(char *str, uint8_t size)
{
	if (check_oppos(str, size) == 0 || check_n_number(str, size) == 0)
		return (0);
	return (1);
}
