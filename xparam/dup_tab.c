/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:24:35 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/01 19:34:48 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	*ft_linedup(uint8_t **tab, uint8_t size, uint8_t line)
{
	uint8_t	i;
	uint8_t	*tabline;

	i = 0;
	tabline = malloc(sizeof(int) * size);
	if (tabline == 0)
		return (0);
	while (i < size)
	{
		tabline[i] = tab[line][i];
		i++;
	}
	return (tabline);
}

uint8_t	**ft_freedup(uint8_t **tab, uint8_t j)
{
	uint8_t	i;

	i = 0;
	while (i <= j)
	{
		free(tab[i]);
		i++;
	}
	return (0);
}

uint8_t	**ft_tabdup(uint8_t **tab, uint8_t size)
{
	uint8_t	j;
	uint8_t	**duptab;

	j = 0;
	size = size / 8 + 2;
	duptab = malloc(sizeof(uint8_t *) * size);
	if (duptab == 0)
		return (0);
	while (j < size)
	{
		duptab[j] = ft_linedup(tab, size, j);
		if (duptab == 0)
			return (ft_freedup(duptab, j));
		j++;
	}
	return (duptab);
}
