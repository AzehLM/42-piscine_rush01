/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:17:20 by azeh              #+#    #+#             */
/*   Updated: 2024/10/07 08:24:19 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putstrerror(char *str);
void	print_tab(int **tab, int size);
void	fill_min(int **duptab, int size);
void	fill_max(int **duptab, int size);

void	pre_fill(int **duptab, int size);

size_t	ft_strlen(char *str);

int		solve_tab(int **tab, int index, int size);
int		is_valid_value(int **tab, int value, int index, int max);
int		valid_tab(int **tab, int max);
int		**init_tab(char *str, size_t size);
int		is_valid_param(char *str, int size);
int		**ft_tabdup(int **tab, int size);

int		check_value(int **duptab, int i, int j);

#endif
