/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:58:40 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:06:01 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_lst(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*next;

	if (*lst == NULL)
		return (0);
	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	bubble_sort(t_stack **sort, int size)
{
	int		i;
	t_stack	*ptr1;
	t_stack	*ptr2;

	i = 0;
	if (size > 3)
		size--;
	while (!if_sort(sort))
	{
		ptr1 = *sort;
		ptr2 = ptr1->next;
		if (ptr1->num > ptr2->num)
			ft_swap(sort);
		if (!if_sort(sort))
			ft_rotate(sort);
		i++;
		if (i == size)
		{
			ft_rotate(sort);
			i = 0;
		}
	}
}

t_stack	*stack_dup(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*ret;

	ptr = *stack;
	ret = NULL;
	while (ptr != NULL)
	{
		add_stack(&ret, ptr->num);
		ptr = ptr->next;
	}
	return (ret);
}

void	ft_chunk(t_stack **stack, int size)
{
	int		i;
	int		j;
	int		modulo;
	int		chunk_size;
	t_stack	*ptr;

	i = -1;
	ptr = *stack;
	chunk_size = ft_sqrt(size) / 2;
	modulo = size % chunk_size;
	while (++i < chunk_size)
	{
		j = -1;
		while (++j < size / chunk_size)
		{
			ptr->index = i;
			ptr = ptr->next;
		}
		if (modulo)
		{
			ptr->index = i;
			ptr = ptr->next;
			modulo--;
		}
	}
}
