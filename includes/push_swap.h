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

typedef struct s_pile
{
	int	nbr;
	struct s_pile *next;
}		t_pile;

typedef struct s_begin
{
	struct s_pile *ba;
	struct s_pile *bb;
}		t_begin;

int		ft_checker(int argc, char **argv);
void	set_nbr(t_pile *pile, int argc, char **argv);
void	ft_putstr(char *str, int stat, t_pile *pile);
void	push_swap(t_pile *pile);
void	swap_three(t_pile *pile);
void	ft_reverse(int pos, int nbr_a, int nbr_b, t_pile *pile);
void	swap_top(int type, t_pile *pile);
void	rotate(int type, t_pile *pile);
void	reverse_rotate(int type, t_pile *pile);
void	push(int type, t_pile *pile);

#endif
