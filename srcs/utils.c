/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:40:01 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/31 06:32:32 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *str, int stat, t_piles *piles)
{
	write(stat, str, ft_strlen(str));
	if (stat == 2)
	{
		free(piles->size);
		exit(EXIT_FAILURE);
	}
}

//void	*ft_realloc(void *ptr, size_t size)
//{
//}
