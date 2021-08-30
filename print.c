#include "push_swap.h"

int	print_err(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

void	print_instruct(char inst, char name)
{
	char	instruct[4];
	int		i;

	i = 0;
	instruct[i++] = inst;
	if (inst == 'x')
	{
		instruct[0] = 'r';
		instruct[i++] = 'r';
	}
	instruct[i++] = name;
	instruct[i] = 0;
	ft_putendl_fd(instruct, 1);
}
