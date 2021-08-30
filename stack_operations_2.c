#include "push_swap.h"

void	swap(t_stack *stack, int fl_print)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
	}
	if (fl_print)
		print_instruct('s', stack->name);
}

void	sswap(t_stack *stack_a, t_stack *stack_b, int fl_print)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (fl_print)
		print_instruct('s', 's');
}

void	rotate(t_stack *stack, int fl_print)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->array[stack->top];
		i = stack->top + 1;
		while (--i > 0)
			stack->array[i] = stack->array[i - 1];
		stack->array[i] = tmp;
	}
	if (fl_print)
		print_instruct('r', stack->name);
}

void	rrotate(t_stack *stack_a, t_stack *stack_b, int fl_print)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (fl_print)
		print_instruct('r', 'r');
}

void	rever_rotate(t_stack *stack, int fl_print)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->array[0];
		i = -1;
		while (++i < stack->top)
			stack->array[i] = stack->array[i + 1];
		stack->array[i] = tmp;
	}
	if (fl_print)
		print_instruct('x', stack->name);
}
