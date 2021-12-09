/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:56:46 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 04:46:17 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*ptr;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->num = num;
	new->next = NULL;
	if (*stack != NULL)
	{
		ptr = *stack;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*stack = new;
}

void	ft_swap(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	*stack = b;
	a->next = b->next;
	b->next = a;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	while (b->next != NULL)
		b = b->next;
	*stack = a->next;
	b->next = a;
	a->next = NULL;
}

void	ft_reverse(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	while (b->next != NULL)
	{
		b = b->next;
		a = a->next;
	}
	a->next = NULL;
	b->next = *stack;
	*stack = b;
}

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	if (!a)
		return ;
	*a = ptr->next;
	ptr->next = *b;
	*b = ptr;
}
