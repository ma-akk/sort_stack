#include "checker.h"

static void	print_res(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
		init_stack(&b, argc - 1, 'b');
		b.array = (int *)malloc(a.size * sizeof(int));
		if (b.array != NULL && b.orig != NULL)
		{
			if (read_commands(&a, &b))
				print_res(&a, &b);
			else
				print_err();
		}
		free_stack(&b);
		free_stack(&a);
	}
	return (0);
}
