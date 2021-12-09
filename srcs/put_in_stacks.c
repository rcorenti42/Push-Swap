/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:34 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:04:08 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_a_make(t_stack **a, int rot, int a_size)
{
	if (rot > a_size - rot)
	{
		while (a_size - rot)
		{
			ft_reverse(a);
			ft_putstr_fd("rra\n", 1);
			a_size--;
		}
	}
	else
	{
		while (rot)
		{
			ft_rotate(a);
			ft_putstr_fd("ra\n", 1);
			rot--;
		}
	}
}

static int	put_in_a_rot(t_stack **ptr_a, int rot)
{
	ft_rotate(ptr_a);
	return (rot + 1);
}

void	put_in_a(t_stack **a, t_stack **b, int a_size)
{
	int		rot;
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	t_stack	*ptr;

	rot = 0;
	ptr_a = stack_dup(a);
	ptr_b = *b;
	ptr = ptr_a;
	if (ptr_a != NULL && !up_or_down(a, ptr_b->num, 0))
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (!(ptr_b->num < ptr_a->num && ptr_b->num > ptr->num))
		{
			rot = put_in_a_rot(&ptr_a, rot);
			ptr = ptr_a;
			while (ptr->next != NULL)
				ptr = ptr->next;
		}
		put_in_a_make(a, rot, a_size);
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
	ft_free_lst(&ptr_a);
}

static void	put_in_b_make(t_stack **b, int up, int b_size)
{
	if (up < b_size - up)
	{
		while (up)
		{
			ft_rotate(b);
			ft_putstr_fd("rb\n", 1);
			up--;
		}
	}
	else
	{
		while (b_size - up)
		{
			ft_reverse(b);
			ft_putstr_fd("rrb\n", 1);
			b_size--;
		}
	}
}

void	put_in_b(t_stack **a, t_stack **b, int b_size)
{
	int		up;
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	up = 0;
	ptr_a = *a;
	ptr_b = stack_dup(b);
	if (ptr_b != NULL && !up_or_down(b, ptr_a->num, 1))
	{
		while (!(ptr_a->num < ptr_b->num && ptr_a->num > ptr_b->next->num))
		{
			up++;
			ft_rotate(&ptr_b);
		}
		up++;
		put_in_b_make(b, up, b_size);
	}
	ft_push(a, b);
	ft_putstr_fd("pb\n", 1);
	ft_free_lst(&ptr_b);
}
