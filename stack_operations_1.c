#include "push_swap.h"

void	init_stack(t_stack *stack, int size, char name)
{
	stack->orig = NULL;
	stack->array = NULL;
	if (size > 0)
		stack->orig = (int *)malloc(sizeof(int) * size);
	stack->name = name;
	stack->size = size;
	stack->top = -1;
}

int	input_stack(t_stack *stack, int argc, char *argv[])
{
	int	index;
	int	num;
	int	i;

	if (stack->orig == NULL)
		return (-1);
	i = 0;
	while (++i < argc)
	{
		if (check_digit(argv[i]))
			return (-1);
		num = ft_atoi(argv[i]);
		stack->top++;
		index = (stack->size - 1) - stack->top;
		stack->orig[index] = num;
	}
	stack->array = copy_orig(stack);
	stack->max = max_in_stack(stack);
	return (check_dupl(stack));
}

int	pop(t_stack *stack)
{
	int	num;

	num = stack->array[stack->top];
	stack->array[stack->top] = 0;
	stack->top--;
	return (num);
}

void	push(t_stack *a, t_stack *b, int fl_print)
{
	if (a->top > -1)
	{
		b->top++;
		b->array[b->top] = pop(a);
	}
	if (fl_print)
		print_instruct('p', b->name);
}

void	rrever_rotate(t_stack *a, t_stack *b, int fl_print)
{
	rever_rotate(a, 0);
	rever_rotate(b, 0);
	if (fl_print)
		print_instruct('x', 'r');
}
