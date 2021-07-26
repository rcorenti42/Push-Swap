#include "push_swap.h"

void	ft_putstr(char *str, int stat)
{
	write(stat, str, ft_strlen(str));
	if (stat == 2)
		exit(EXIT_FAILURE);
}
