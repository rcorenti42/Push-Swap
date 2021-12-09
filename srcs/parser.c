/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:57:02 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 04:52:28 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_sort(t_stack **stack)
{
	int		a;
	int		b;
	t_stack	*ptr;

	b = 0;
	ptr = *stack;
	a = ptr->num;
	ptr = ptr->next;
	if (a > ptr->num)
		return (0);
	while (ptr->next != NULL)
	{
		a = ptr->num;
		ptr = ptr->next;
		if (a > ptr->num)
			return (0);
	}
	return (1);
}

int	up_or_down(t_stack **stack, int nbr, int nb_stack)
{
	int		up;
	int		down;
	t_stack	*ptr;

	ptr = *stack;
	up = ptr->num;
	down = ptr->num;
	while (ptr != NULL)
	{
		if (up < ptr->num)
			up = ptr->num;
		if (down > ptr->num)
			down = ptr->num;
		ptr = ptr->next;
	}
	if (nbr > up || nbr < down)
	{
		if (nb_stack == 0)
			stack_sort(stack, down, 0);
		else
			stack_sort(stack, up, 1);
		return (1);
	}
	return (0);
}

void	if_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
}

void	if_double(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*sort;

	sort = stack_dup(stack);
	bubble_sort(&sort, ft_lstsize(sort));
	ptr = sort;
	while (ptr->next != NULL)
	{
		if (ptr->num == ptr->next->num)
		{
			ft_free_lst(stack);
			ft_free_lst(&sort);
			ft_error();
		}
		ptr = ptr->next;
	}
	ft_free_lst(&sort);
}

void	if_int_min_max(char *str)
{
	long long	i;

	i = ft_atoi(str);
	if (i > 2147483647 || i < -2147483648)
		ft_error();
}
