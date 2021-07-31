/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:10:21 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/31 06:48:08 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(int pos, int nbr_a, int nbr_b, t_piles *piles)
{
	int	i;

	i = piles->nbr[pos][nbr_a];
	piles->nbr[pos][nbr_a] = piles->nbr[pos][nbr_b];
	piles->nbr[pos][nbr_b] = i;
}

void	swap_top(int type, t_piles *piles)
{
	if (type == 1)
	{
		ft_reverse(0, 1, 0, piles);
		ft_putstr("sa", 1, piles);
	}
	else if (type == 2)
	{
		ft_reverse(1, 1, 0, piles);
		ft_putstr("sb", 1, piles);
	}
	else
	{
		ft_reverse(0, 1, 0, piles);
		ft_reverse(1, 1, 0,piles);
		ft_putstr("ss", 1, piles);
	}
}

void	rotate(int type, t_piles *piles)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (++i < piles->size[0])
			ft_reverse(0, i, i - 1, piles);
		ft_putstr("ra", 1, piles);
	}
	else if (type == 2)
	{
		while (++i < piles->size[1])
			ft_reverse(1, i, i - 1, piles);
		ft_putstr("rb", 1, piles);
	}
	else
	{
		while (++i < piles->size[0])
			ft_reverse(0, i, i - 1, piles);
		i = 0;
		while (++i < piles->size[1])
			ft_reverse(1, i, i - 1, piles);
		ft_putstr("rr", 1, piles);
	}
}

void	reverse_rotate(int type, t_piles *piles)
{
	int	i;

	if (type == 1)
	{
		i = piles->size[0];
		while (--i > 0)
			ft_reverse(0, i, i - 1, piles);
		ft_putstr("rra", 1, piles);
	}
	else if (type == 2)
	{
		i = piles->size[1];
		while (--i > 0)
			ft_reverse(1, i, i - 1, piles);
		ft_putstr("rrb", 1, piles);
	}
	else
	{
		i = piles->size[0];
		while (--i > 0)
			ft_reverse(0, i, i - 1, piles);
		i = piles->size[1];
		while (--i > 0)
			ft_reverse(1, i, i - 1, piles);
		ft_putstr("rrr", 1, piles);
	}
}

void	push(int type, t_piles *piles)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		piles->nbr[0][piles->size[0]] = piles->nbr[1][0];
		*piles->nbr[1][0] = NULL;
		while (++i < piles->size[1])
			ft_reverse(1, i, i - 1, piles);
		i = piles->size[0];
		while (--i > 0)
			ft_reverse(0, i, i - 1, piles);
		ft_putstr("pa", 1, piles);
	}
	else
	{
		piles->nbr[1][piles->size[1]] = piles->nbr[0][0];
		*piles->nbr[0][0] = NULL;
		while (++i < piles->size[0])
			ft_reverse(0, i, i - 1, piles);
		i = piles->size[1];
		while (--i > 0)
			ft_reverse(1, i, i - 1, piles);
		ft_putstr("pb", 1, piles);
	}
}
