/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:44:07 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/28 07:44:10 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_piles
{
	int	*size;
	int	**nbr;
}		t_piles;

int		ft_checker(int argc, char **argv);
void	set_nbr(t_piles *piles, int argc, char **argv);
void	ft_putstr(char *str, int stat, t_piles *piles);

#endif
