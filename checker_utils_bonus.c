#include "checker.h"

char	**input_set_comm(void)
{
	char	**set_comm;

	set_comm = (char **)malloc(12 * sizeof(char *));
	if (set_comm != NULL)
	{
		set_comm[0] = ft_strdup("sa");
		set_comm[1] = ft_strdup("sb");
		set_comm[2] = ft_strdup("ss");
		set_comm[3] = ft_strdup("pa");
		set_comm[4] = ft_strdup("pb");
		set_comm[5] = ft_strdup("ra");
		set_comm[6] = ft_strdup("rb");
		set_comm[7] = ft_strdup("rr");
		set_comm[8] = ft_strdup("rra");
		set_comm[9] = ft_strdup("rrb");
		set_comm[10] = ft_strdup("rrr");
		set_comm[11] = NULL;
	}
	return (set_comm);
}

int	check_commands(char *commands, char **set_comm)
{
	int	i;

	i = -1;
	while (set_comm && ++i < 11)
		if (!ft_strncmp(commands, set_comm[i], ft_strlen(set_comm[i]) + 1))
			return (0);
	return (1);
}

void	choice_command(char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "sa", 3))
		swap(a, 0);
	if (!ft_strncmp(command, "sb", 3))
		swap(b, 0);
	if (!ft_strncmp(command, "ss", 3))
		sswap(a, b, 0);
	if (!ft_strncmp(command, "ra", 3))
		rotate(a, 0);
	if (!ft_strncmp(command, "rb", 3))
		rotate(b, 0);
	if (!ft_strncmp(command, "rr", 3))
		rrotate(a, b, 0);
	if (!ft_strncmp(command, "pa", 3))
		push(b, a, 0);
	if (!ft_strncmp(command, "pb", 3))
		push(a, b, 0);
	if (!ft_strncmp(command, "rra", 4))
		rever_rotate(a, 0);
	if (!ft_strncmp(command, "rrb", 4))
		rever_rotate(b, 0);
	if (!ft_strncmp(command, "rrr", 4))
		rrever_rotate(a, b, 0);
}

void	free_commands(char *command, char **set_comm)
{
	int	i;

	i = -1;
	if (command != NULL)
		free(command);
	command = NULL;
	if (set_comm != NULL)
	{
		while (set_comm[++i] != NULL)
			free(set_comm[i]);
		free(set_comm);
		set_comm = NULL;
	}
}

int	read_commands(t_stack *a, t_stack *b)
{
	char	*command;
	int		fl_res;
	char	**set_comm;
	int		i;

	set_comm = input_set_comm();
	fl_res = 1;
	command = NULL;
	i = get_next_line(0, &command);
	while (i > 0)
	{
		if (check_commands(command, set_comm))
			fl_res = 0;
		choice_command(command, a, b);
		my_free(command);
		i = get_next_line(0, &command);
	}
	if (i == 0 && command[0] != 0)
		fl_res = 0;
	free_commands(command, set_comm);
	return (fl_res);
}
