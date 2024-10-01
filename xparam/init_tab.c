/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeh <azeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:55:50 by azeh              #+#    #+#             */
/*   Updated: 2024/09/30 10:29:11 by azeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_borders(int **tab, char *str)
{
	int	strindex;
	int	tabindex;
	int	n;
	int	len;

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
}

int	**init_tab(char *str, size_t size)
{
	int		i;
	int		j;
	int		grid_size;
	int		**tab;

	(void) str;
	grid_size = ((size / 8) + 2);
	tab = malloc(grid_size * sizeof(int *));
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
	init_borders(tab, str);
	return (tab);
}
