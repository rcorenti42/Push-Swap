/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hold_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:22 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:03:28 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_put_rotate(t_stack **stack)
{
	ft_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

static void	ft_put_reverse(t_stack **stack)
{
	ft_reverse(stack);
	ft_putstr_fd("rra\n", 1);
}

void	put_hold_top(t_stack **a, int hold, int size)
{
	int		up;
	t_stack	*ptr;

	up = 0;
	ptr = *a;
	while (ptr->num != hold)
	{
		up++;
		size--;
		ptr = ptr->next;
	}
	if (up < size)
	{
		while (up--)
			ft_put_rotate(a);
	}
	else
	{
		while (size--)
			ft_put_reverse(a);
	}
}
