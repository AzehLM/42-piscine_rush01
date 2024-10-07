/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:47:33 by gueberso          #+#    #+#             */
/*   Updated: 2024/10/05 17:23:18 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pre_fill(int **duptab, int size)
{
	fill_max(duptab, size);
	fill_min(duptab, size);
}
