/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:55:50 by azeh              #+#    #+#             */
/*   Updated: 2024/10/01 18:24:55 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	**init_borders(uint8_t **tab, char *str)
{
	uint8_t	strindex;
	uint8_t	tabindex;
	uint8_t	n;
	uint8_t	len;

	len = ft_strlen(str);
	n = (len + 1) / 8;
	strindex = 0;
	tabindex = 1;
	while (strindex < len)
	{
		if (strindex < 2 * n - 1)
			tab[0][tabindex] = str[strindex] - '0';
		else if (strindex < 4 * n - 1)
			tab[n + 1][tabindex] = str[strindex] - '0';
		else if (strindex < 6 * n - 1)
			tab[tabindex][0] = str[strindex] - '0';
		else
			tab[tabindex][n + 1] = str[strindex] - '0';
		tabindex++;
		if (tabindex % (n + 1) == 0)
			tabindex = 1;
		strindex += 2;
	}
	return (tab);
}

uint8_t	**init_tab(char *str, size_t size)
{
	uint8_t		i;
	uint8_t		j;
	uint8_t		grid_size;
	uint8_t		**tab;

	grid_size = ((size / 8) + 2);
	tab = malloc(grid_size * sizeof(uint8_t *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < grid_size)
	{
		tab[i] = malloc(grid_size * sizeof(int));
		if (!tab)
			return (NULL);
		i++;
	}
	j = 0;
	while (j < (grid_size * grid_size))
	{
		tab[j / grid_size][j % grid_size] = 0;
		j++;
	}
	tab = init_borders(tab, str);
	return (tab);
}
