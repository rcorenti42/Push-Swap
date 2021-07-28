#include "push_swap.h"

void	ft_putstr(char *str, int stat, t_piles *piles)
{
	write(stat, str, ft_strlen(str));
	if (stat == 2)
	{
		free(piles->size);
		exit(EXIT_FAILURE);
	}
}
