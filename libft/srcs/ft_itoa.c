/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 06:42:45 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/27 23:02:41 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_get_size(int number)
{
	int	count;

	count = 0;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_utils(int n, int size, int neg, char *tab)
{
	if (neg)
		tab[0] = '-';
	tab[size + neg] = '\0';
	while (size)
	{
		if (neg)
			tab[size] = n % 10 + '0';
		else
			tab[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*tab;

	size = ft_get_size(n);
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	tab = (char *)malloc(sizeof(char) * (size + 1 + neg));
	if (tab == NULL)
		return (NULL);
	return (ft_utils(n, size, neg, tab));
}
