#include "push_swap.h"

static int	binary_search(int *arr, int size, int item)
{
	int	low;
	int	mid;
	int	high;

	low = 0;
	high = size - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == item)
			return (mid);
		if (arr[mid] < item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (low);
}

void	create_new_arr(t_stack *a)
{
	int	i;

	i = -1;
	quick_sort_arr(a->orig, a->size - 1);
	while (++i < a->size)
		a->array[i] = a->top - binary_search(a->orig, a->size, a->array[i]);
}

void	radix_sort(t_stack *a, t_stack *b, int max_bit)
{
	int	i;
	int	j;

	i = -1;
	while (++i < max_bit)
	{
		if (!is_sorted(a))
		{
			j = -1;
			while (++j < a->size)
			{
				if (!(is_sorted(a) && b->top == -1))
				{
					if (((a->array[a->top] >> i) & 1) == 1)
						rotate(a, 1);
					else
						push(a, b, 1);
				}
			}
			while (b->top != -1)
				push(b, a, 1);
		}
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	max_bit;

	if (a->size <= 5)
		sort_small_stack(a, b, a->size);
	else
	{
		create_new_arr(a);
		max_bit = 0;
		while ((a->max >> max_bit) != 0)
			++max_bit;
		radix_sort(a, b, max_bit);
	}
}
