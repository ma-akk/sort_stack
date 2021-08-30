#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		init_stack(&a, argc - 1, 'a');
		if (input_stack(&a, argc, argv))
		{
			free_stack(&a);
			return (print_err());
		}
		if (!is_sorted(&a) && argc > 2)
		{
			init_stack(&b, argc - 1, 'b');
			b.array = (int *)malloc(a.size * sizeof(int));
			if (b.array != NULL && b.orig != NULL)
				sort_stack(&a, &b);
			free_stack(&b);
		}
		free_stack(&a);
	}
	return (0);
}
