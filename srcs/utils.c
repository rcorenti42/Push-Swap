/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:40:01 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/28 07:40:04 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str, int stat, t_piles *piles)
{
	write(stat, str, ft_strlen(str));
	if (stat == 2)
	{
		free(piles->size);
		exit(EXIT_FAILURE);
	}
}
