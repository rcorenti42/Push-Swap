/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 02:39:20 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/27 22:46:32 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*place;

	place = NULL;
	place = malloc(size * elements);
	if (place == NULL)
		return (NULL);
	ft_bzero(place, elements * size);
	return (place);
}
