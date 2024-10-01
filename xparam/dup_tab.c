/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:24:35 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/01 18:23:02 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int *ft_linedup(int **tab, int size, int line)
{
    int i;
    int    *tabline;

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

int    **ft_freedup(int **tab, int j)
{
    int    i;

    i = 0;
    while (i <= j)
    {
        free(tab[i]);
        i++;
    }
    return (0);
}

int    **ft_tabdup(int **tab, int size)
{
    int    j;
    int    **duptab;

    j = 0;
    size = size / 8 + 2;
    duptab = malloc(sizeof(int *) * size);
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
