/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:54:11 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/31 03:17:47 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_three(t_piles *piles)
{
	if (piles->size[0] == 2)
	{
		if (piles->nbr[0][0] > piles->nbr[0][1])
			ft_putstr("sa\n", 1, piles);
	}
	else
	{
		if (piles->nbr[0][0] > piles->nbr[0][1])
		{
			if (piles->nbr[0][2] > piles->nbr[0][0])
				ft_putstr("sa\n", 1, piles);
			else if (piles->nbr[0][1] > piles->nbr[0][2])
				ft_putstr("sa\nrra\n", 1, piles);
			else
				ft_putstr("ra\n", 1, piles);
		}
		else
		{
			if (piles->nbr[0][0] > piles->nbr[0][2])
				ft_putstr("rra\n", 1, piles);
			else
				ft_putstr("sa\nra\n", 1, piles);
		}
	}
}

void	swap_five(t_piles *piles)
{
}

//void	swap_hundred(t_piles *piles)
//{
//}

//void	swap_more(t_piles *piles)
//{
//}

void	push_swap(t_piles *piles)
{
	if (piles->size[0] <= 3)
		swap_three(piles);
	else if (piles->size[0] <= 5)
		swap_five(piles);
//	else if (piles->size[0] <= 100)
//		swap_hundred(piles);
//	else
//		swap_more(piles);
}
