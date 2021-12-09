/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:56:30 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:02:27 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_sort_put(t_stack **stack, int step, int size, int nb_stack)
{
	if (step < size - step)
	{
		while ((step--) > 0)
		{
			ft_rotate(stack);
			if (nb_stack == 0)
				ft_putstr_fd("ra\n", 1);
			else
				ft_putstr_fd("rb\n", 1);
		}
	}
	else
	{
		while ((size--) - step > 0)
		{
			ft_reverse(stack);
			if (nb_stack == 0)
				ft_putstr_fd("rra\n", 1);
			else
				ft_putstr_fd("rrb\n", 1);
		}
	}
}

void	stack_sort(t_stack **stack, int nb, int nb_stack)
{
	int		step;
	int		size;
	t_stack	*ptr;

	step = 0;
	size = ft_lstsize(*stack);
	ptr = *stack;
	if (size == 2)
		size++;
	while (ptr->num != nb)
	{
		step++;
		ptr = ptr->next;
	}
	stack_sort_put(stack, step, size, nb_stack);
}

static void	all_in_a(t_stack **a, t_stack **b)
{
	int		up;
	t_stack	*ptr;

	ptr = *b;
	up = ptr->num;
	while (ptr != NULL)
	{
		if (up < ptr->num)
			up = ptr->num;
		ptr = ptr->next;
	}
	stack_sort(b, up, 1);
	while (*b != NULL)
	{
		ft_push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
}

static void	ft_big_sort(t_stack **a, t_stack **sort, int size)
{
	t_stack	*b;

	b = NULL;
	while (*a != NULL)
	{
		put_hold_top(a, ft_scan(a, sort, size), ft_lstsize(*a));
		put_in_b(a, &b, ft_lstsize(b));
	}
	all_in_a(a, &b);
}

void	big_stack(t_stack **stack, int size)
{
	t_stack	*sort;

	sort = stack_dup(stack);
	bubble_sort(&sort, size);
	ft_chunk(&sort, size);
	ft_big_sort(stack, &sort, size);
	ft_free_lst(&sort);
}
