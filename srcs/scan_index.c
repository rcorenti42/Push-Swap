/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:50 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:04:35 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_index(t_stack **a, t_stack **sort)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	ptr2 = *sort;
	while (ptr2 != NULL)
	{
		ptr1 = *a;
		while (ptr1 != NULL)
		{
			if (ptr1->num == ptr2->num)
				return (ptr2->index);
			ptr1 = ptr1->next;
		}
		ptr2 = ptr2->next;
	}
	return (0);
}

static int	set_step(int up, int down, int step)
{
	if (up < step)
		return (up);
	else
		return (down);
}

int	ft_scan(t_stack **a, t_stack **sort, int down)
{
	int		up;
	int		step;
	int		num;
	t_stack	*ptr1;
	t_stack	*ptr2;

	up = 0;
	step = down;
	ptr1 = *a;
	while (ptr1 != NULL)
	{
		ptr2 = *sort;
		while (ptr1->num != ptr2->num)
			ptr2 = ptr2->next;
		if (ptr2->index == ft_index(a, sort))
			if (up < step || down < step)
				num = ptr1->num;
		if (ptr2->index == ft_index(a, sort))
			if (up < step || down < step)
				step = set_step(up, down, step);
		ptr1 = ptr1->next;
		up++;
		down--;
	}
	return (num);
}
