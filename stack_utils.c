#include "push_swap.h"

int	max_in_stack(t_stack *stack)
{
	int	i;
	int	max;

	i = -1;
	if (stack->array != NULL)
	{
		max = stack->array[0];
		while (++i < stack->size)
			if (max < stack->array[i])
				max = stack->array[i];
		return (max);
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top + 1;
	while (--i > 0)
		if (stack->array[i] > stack->array[i - 1])
			return (0);
	return (1);
}

int	*copy_orig(t_stack *a)
{
	int	i;
	int	*new_arr;

	i = -1;
	new_arr = (int *)malloc(a->size * sizeof(int));
	if (new_arr != NULL)
		while (++i < a->size)
			new_arr[i] = a->orig[i];
	return (new_arr);
}

static void	swap_arr(int *arr, int *left, int *rigth)
{
	int	tmp;

	tmp = arr[*left];
	arr[*left] = arr[*rigth];
	arr[*rigth] = tmp;
	(*left)++;
	(*rigth)--;
}

void	quick_sort_arr(int *arr, int n)
{
	int	basic;
	int	left;
	int	rigth;

	basic = arr[n >> 1];
	left = 0;
	rigth = n;
	while (left <= rigth)
	{
		while (arr[left] > basic)
			left++;
		while (arr[rigth] < basic)
			rigth--;
		if (left <= rigth)
			swap_arr(arr, &left, &rigth);
	}
	if (left < n)
		quick_sort_arr(arr + left, n - left);
	if (rigth > 0)
		quick_sort_arr(arr, rigth);
}
