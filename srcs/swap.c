/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:54:11 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/31 06:38:11 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_three(t_piles *piles)
{
	if (piles->size[0] == 2)
	{
		if (piles->nbr[0][0] > piles->nbr[0][1])
			swap_top(1, piles);
	}
	else
	{
		if (piles->nbr[0][0] > piles->nbr[0][1])
		{
			if (piles->nbr[0][2] > piles->nbr[0][0])
				swap_top(1, piles);
			else if (piles->nbr[0][1] > piles->nbr[0][2])
			{
				swap_top(1, piles);
				rotate(1, piles);
			}
			else
				rotate(1, piles);
		}
		else
		{
			if (piles->nbr[0][0] > piles->nbr[0][2])
				reverse_rotate(1, piles);
			else
			{
				swap_top(1, piles);
				rotate(1, piles);
			}
		}
	}
}

//void	swap_five(t_piles *piles)
//{
//}

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
//	else if (piles->size[0] <= 5)
//		swap_five(piles);
//	else if (piles->size[0] <= 100)
//		swap_hundred(piles);
//	else
//		swap_more(piles);
}
