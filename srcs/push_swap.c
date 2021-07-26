#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_checker(argc, argv))
	{
		ft_putstr("Error", 2);
		return (0);
	}
	//set_nbr();
	return (0);
}

int	ft_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	sign;

	i = 1;
	j = 0;
	sign = 0;
	argc--;
	while (argc)
	{
		while (argv[i][j])
		{
			if (!sign || (argv[i][j] != '+' && argv[i][j] != '-'))
				sign++;
			else if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		sign = 0;
		j = 0;
		argc--;
	}
	return (1);
}


