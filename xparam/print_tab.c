/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:24:37 by azeh              #+#    #+#             */
/*   Updated: 2024/10/07 22:32:40 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(uint8_t **tab, uint8_t size)
{
	uint8_t	i;
	uint8_t	j;
	uint8_t	grid_size;

	i = 1;
	grid_size = ((size / 8) + 1);
	while (i < grid_size)
	{
		j = 1;
		while (j < grid_size)
		{
			ft_putchar(tab[i][j] + 48);
			j++;
			if (j != grid_size)
				ft_putchar(' ');
			else if (j == grid_size)
				ft_putchar('\n');
		}
		i++;
	}
}
