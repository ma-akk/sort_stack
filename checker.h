#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

char	**input_set_comm(void);
int		check_commands(char *commands, char **set_comm);
void	choice_command(char *command, t_stack *a, t_stack *b);
void	free_commands(char *command, char **set_comm);
int		read_commands(t_stack *a, t_stack *b);

#endif