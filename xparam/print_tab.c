/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeh <azeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:24:37 by azeh              #+#    #+#             */
/*   Updated: 2024/09/30 10:26:40 by azeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_tab(int **tab, int size)
{
	int	i;
	int	j;
	int	grid_size;
	
	i = 0;
	grid_size = ((size / 8) + 2);
	while (i < grid_size)
	{
		j = 0;
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
