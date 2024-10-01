/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:17:20 by azeh              #+#    #+#             */
/*   Updated: 2024/10/01 12:42:16 by gueberso         ###   ########.fr       */
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

size_t	ft_strlen(char *str);

int	**init_tab(char *str, size_t size);
int	is_valid_param(char *str, int size);
int	**ft_tabdup(int **tab, int size);

#endif
