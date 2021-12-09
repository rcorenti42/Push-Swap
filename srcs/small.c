/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:58:02 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:05:14 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_size_three_continue(t_stack **a, int num, int next)
{
	if (num > next)
	{
		ft_reverse(a);
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		ft_swap(a);
		ft_rotate(a);
		ft_putstr_fd("sa\nra\n", 1);
	}
}

static void	ft_size_three(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr->num > ptr->next->num)
	{
		if (ptr->next->num > ptr->next->next->num)
		{
			ft_swap(a);
			ft_reverse(a);
			ft_putstr_fd("sa\nrra\n", 1);
		}
		else if (ptr->num > ptr->next->next->num)
		{
			ft_rotate(a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			ft_swap(a);
			ft_putstr_fd("sa\n", 1);
		}
	}
	else
		ft_size_three_continue(a, ptr->num, ptr->next->next->num);
}

static void	little_end(t_stack **stack)
{
	int		min;
	t_stack	*ptr;

	ptr = *stack;
	min = ptr->num;
	while (ptr != NULL)
	{
		if (min > ptr->num)
			min = ptr->num;
		ptr = ptr->next;
	}
	stack_sort(stack, min, 0);
}

static void	ft_little_sort(t_stack **a)
{
	t_stack	*b;
	t_stack	*ptr1;

	b = NULL;
	ptr1 = *a;
	ft_push(a, &b);
	ft_putstr_fd("pb\n", 1);
	if (ft_lstsize(*a) != 3)
	{
		ft_push(a, &b);
		ft_putstr_fd("pb\n", 1);
	}
	if (!if_sort(a))
		ft_size_three(a);
	while (b != NULL)
		put_in_a(a, &b, ft_lstsize(*a));
	if (!if_sort(a))
		little_end(a);
}

void	small_stack(t_stack **stack, int size)
{
	if (size == 2)
	{
		if (!if_sort(stack))
			ft_putstr_fd("sa\n", 1);
	}
	else if (size == 3)
		ft_size_three(stack);
	else
		ft_little_sort(stack);
}
