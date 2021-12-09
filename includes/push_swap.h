/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:29:26 by rcorenti          #+#    #+#             */
/*   Updated: 2021/12/09 05:11:57 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack {
	int				num;
	int				index;
	struct s_stack	*next;
}			t_stack;

long long	ft_atoi(char *str);
int			ft_free_lst(t_stack **lst);
void		add_stack(t_stack **stack, int num);
int			if_sort(t_stack **stack);
void		if_num(char *str);
void		if_double(t_stack **stack);
void		if_int_min_max(char *str);
void		big_stack(t_stack **stack, int size);
void		small_stack(t_stack **stack, int size);
void		ft_rotate(t_stack **stack);
void		ft_reverse(t_stack **stack);
void		ft_push(t_stack **a, t_stack **b);
void		put_hold_top(t_stack **a, int hold, int size);
void		put_in_a(t_stack **a, t_stack **b, int a_size);
void		put_in_b(t_stack **a, t_stack **b, int b_size);
int			ft_scan(t_stack **a, t_stack **sort, int down);
void		ft_putstr_fd(char *str, int fd);
int			ft_lstsize(t_stack *lst);
void		bubble_sort(t_stack **sort, int size);
t_stack		*stack_dup(t_stack **stack);
void		ft_chunk(t_stack **stack, int size);
void		ft_error(void);
void		stack_sort(t_stack **stack, int nb, int nb_stack);
int			up_or_down(t_stack **stack, int nbr, int nb_stack);
void		ft_swap(t_stack **stack);
int			ft_sqrt(int nb);

#endif
