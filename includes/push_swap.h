/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:44:07 by rcorenti          #+#    #+#             */
/*   Updated: 2021/07/30 06:29:41 by rcorenti         ###   ########.fr       */
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
void	push_swap(t_piles *piles);
void	swap_three(t_piles *piles);
void	ft_reverse(int pos, int nbr_a, int nbr_b, t_piles *piles);
void	swap_top(int type, t_piles *piles);
void	rotate(int type, t_piles *piles);
void	reverse_rotate(int type, t_piles *piles);
void	push(int type, t_piles *piles);

#endif
