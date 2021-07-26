#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/includes/libft.h"

typedef struct	s_pile
{
	int	*size;
	int	*nbr;
}		t_pile;

int	ft_checker(int argc, char **argv);
void	ft_putstr(char *str, int stat);

#endif
