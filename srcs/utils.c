/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:58:20 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:05:42 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

long long	ft_atoi(char *str)
{
	long long	ret;
	int			c;
	int			neg;

	ret = 0;
	c = 0;
	neg = 0;
	while (str[c] == '\t' || str[c] == '\n' || str[c] == '\v'
		|| str[c] == '\f' || str[c] == '\r' || str[c] == ' ')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			neg++;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		ret = ret * 10 + str[c] - '0';
		c++;
	}
	if (neg)
		ret = -ret;
	return (ret);
}
