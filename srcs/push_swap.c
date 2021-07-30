/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:37:17 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/29 05:18:07 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	sign;

	i = 1;
	j = 0;
	sign = 0;
	while (--argc)
	{
		while (argv[i][j])
		{
			if (!sign && (argv[i][j] == '+' || argv[i][j] == '-'))
				sign++;
			else if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		sign = 0;
		j = 0;
	}
	return (1);
}

void	set_nbr(t_piles *piles, int argc, char **argv)
{
	int	i;

	i = 0;
	piles->nbr = malloc(sizeof(int *) * 2);
	piles->nbr[0] = malloc(sizeof(int) * argc - 1);
	piles->nbr[1] = malloc(sizeof(int) * argc - 1);
	while (--argc)
	{
		piles->nbr[0][i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_piles	piles;

	piles.size = malloc(sizeof(int) * 2);
	if (piles.size == NULL)
		ft_putstr("Error", 2, &piles);
	piles.size[0] = argc - 1;
	piles.size[1] = 0;
	if (argc < 2)
		return (0);
	if (!ft_checker(argc, argv))
		ft_putstr("Error", 2, &piles);
	set_nbr(&piles, argc, argv);
	push_swap(&piles);
	free(piles.size);
	return (0);
}
