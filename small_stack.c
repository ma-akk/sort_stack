#include "push_swap.h"

void	sort_stack2(t_stack *stack)
{
	if (stack->array[stack->top] > stack->array[stack->top - 1])
		swap(stack, 1);
}

void	sort_stack3(t_stack *a)
{
	if (a->array[a->top] > a->array[a->top - 1])
	{
		if (a->array[a->top] > a->array[a->top - 2])
			rotate(a, 1);
		if (a->array[a->top] < a->array[a->top - 2] && \
		a->array[a->top] > a->array[a->top - 1])
			swap(a, 1);
	}
	else
	{
		if (a->array[a->top] > a->array[a->top - 2])
			rever_rotate(a, 1);
		else if (a->array[a->top - 1] > a->array[a->top - 2])
		{
			swap(a, 1);
			rotate(a, 1);
		}
	}
}

static int	def_mediana(t_stack *stack)
{
	int	*arr_stack;
	int	i;
	int	j;

	arr_stack = (int *)malloc(stack->size * sizeof(int));
	i = -1;
	while (++i <= stack->top)
	{
		j = i;
		while (j > 0 && arr_stack[j - 1] > stack->array[i])
		{
			arr_stack[j] = arr_stack[j - 1];
			j--;
		}
		arr_stack[j] = stack->array[i];
	}
	j = arr_stack[(stack->size / 2)];
	free(arr_stack);
	return (j);
}

void	sort_stack5(t_stack *a, t_stack *b)
{
	int	med;
	int	i;

	med = def_mediana(a);
	i = a->size;
	while (--i > -1)
	{
		if (a->array[a->top] > med)
			push(a, b, 1);
		else
			rotate(a, 1);
	}
	sort_small_stack(a, b, a->top + 1);
	sort_small_stack(b, a, b->top + 1);
	while (b->top > -1)
	{
		push(b, a, 1);
		rotate(a, 1);
	}
}

void	sort_small_stack(t_stack *a, t_stack *b, int fl_count)
{
	if (a->top == 1 || fl_count == 2)
		sort_stack2(a);
	if (a->top == 2)
		sort_stack3(a);
	if (a->top > 2)
		sort_stack5(a, b);
}
