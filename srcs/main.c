/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:35:20 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 03:54:15 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = NULL;
	if (argc < 3)
		return (0);
	while (argv[++i])
	{
		if_num(argv[i]);
		if_int_min_max(argv[i]);
	}
	i = 0;
	while (argv[++i])
		add_stack(&a, (int)ft_atoi(argv[i]));
	if_double(&a);
	if (if_sort(&a))
		return (ft_free_lst(&a));
	if (argc <= 6)
		small_stack(&a, argc - 1);
	else
		big_stack(&a, argc - 1);
	ft_free_lst(&a);
	return (0);
}
