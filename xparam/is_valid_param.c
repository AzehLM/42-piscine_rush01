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

int	check_n_number(char *str, int size)
{
	int	i;
	int	count;
	int	grid_size;

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

int	check_oppos(char *str, int size)
{
	int	i;
	int	j;
	int	grid_size;
	int	gridouble;

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

int	is_valid_param(char *str, int size)
{
	if (check_oppos(str, size) == 0 || check_n_number(str, size) == 0)
		return (0);
	return (1);
}
