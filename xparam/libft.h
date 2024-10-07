/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:17:20 by azeh              #+#    #+#             */
/*   Updated: 2024/10/07 14:23:58 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putstrerror(char *str);
void	print_tab(uint8_t **tab, uint8_t size);
void	fill_min(uint8_t **duptab, uint8_t size);
void	fill_max(uint8_t **duptab, uint8_t size);

void	pre_fill(uint8_t **duptab, uint8_t size);

size_t	ft_strlen(char *str);

uint8_t		solve_tab(uint8_t **tab, uint8_t index, uint8_t size);
uint8_t		is_valid_value(uint8_t **tab, uint8_t value, uint8_t index, uint8_t max);
uint8_t		valid_tab(uint8_t **tab, uint8_t max);
uint8_t		**init_tab(char *str, size_t size);
uint8_t		is_valid_param(char *str, uint8_t size);
uint8_t		**ft_tabdup(uint8_t **tab, uint8_t size);
uint8_t		check_line(uint8_t **tab, uint8_t line, uint8_t max);
uint8_t		check_row(uint8_t **tab, uint8_t row, uint8_t max);
uint8_t		check_value(uint8_t **duptab, uint8_t i, uint8_t j);

#endif
