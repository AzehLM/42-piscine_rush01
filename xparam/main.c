/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:15:22 by azeh              #+#    #+#             */
/*   Updated: 2024/10/07 22:34:03 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	check_arg(char *av)
{
	uint8_t	i;
	uint8_t	size;

	i = 0;
	size = ft_strlen(av);
	if ((size + 1) / 8 >= 2 && (size + 1) / 8 <= 9 && ((size + 1) % 8 == 0))
	{
		while (av && av[i])
		{
			if (i % 2 == 0 && (av[i] < '1' || av[i] > (((size + 1) / 8) + 48)))
			{
				return (0);
			}
			if (i % 2 == 1 && (av[i] != ' '))
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

void	free_tabs(uint8_t size, uint8_t **tab)
{
	uint8_t	i;

	i = 0;
	while (i < (size / 8) + 2)
		free(tab[i++]);
	free(tab);
}

int	main(int ac, char **av)
{
	uint8_t		**tab;
	size_t		size;

	size = ft_strlen(av[1]) + 1;
	if (ac != 2 || check_arg(av[1]) == 0 || is_valid_param(av[1], size) == 0)
	{
		ft_putstrerror("Error, invalid argument.\n");
		return (-1);
	}
	tab = init_tab(av[1], size);
	if (!tab)
		return (-1);
	pre_fill(tab, size);
	if (solve_tab(tab, 0, size))
		print_tab(tab, size);
	else
		printf("Error, no solution\n");
	free_tabs(size, tab);
	return (0);
}
