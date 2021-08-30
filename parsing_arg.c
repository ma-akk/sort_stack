#include "push_swap.h"

int	check_int(char *str, int zn)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	if (str[i] == 0)
		return (-1);
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if ((nbr > MAXINT && zn == 1) || \
		(nbr > 2147483648 && zn == -1))
			return (-1);
		i++;
	}
	return (0);
}

int	check_digit(char *argv)
{
	int	i;
	int	zn;

	i = -1;
	zn = 1;
	if (argv[0] == '-' || argv[0] == '+')
	{
		if (argv[0] == '-')
			zn = -1;
		i++;
	}
	while (argv[++i])
		if (!ft_isdigit(argv[i]))
			return (-1);
	if (check_int(argv, zn))
		return (-1);
	return (0);
}

int	check_dupl(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (-1);
			j++;
		}
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	if (stack->array != NULL)
		free(stack->array);
	stack->array = NULL;
	if (stack->orig != NULL)
		free(stack->orig);
	stack->orig = NULL;
}
