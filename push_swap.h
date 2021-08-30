#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define MAXINT 2147483647

typedef struct s_stack
{
	char	name;
	int		size;
	int		max;
	int		top;
	int		*array;
	int		*orig;
}				t_stack;

void	init_stack(t_stack *stack, int size, char name);
int		input_stack(t_stack *stack, int argc, char *argv[]);
void	swap(t_stack *stack, int fl_print);
void	sswap(t_stack *stack_a, t_stack *stack_b, int fl_print);
void	push(t_stack *stack_a, t_stack *stack_b, int fl_print);
int		pop(t_stack *stack);
void	rotate(t_stack *stack, int fl_print);
void	rrotate(t_stack *stack_a, t_stack *stack_b, int fl_print);
void	rever_rotate(t_stack *stack, int fl_print);
void	rrever_rotate(t_stack *stack_a, t_stack *stack_b, int fl_print);

int		check_int(char *str, int zn);
int		check_digit(char *argv);
int		check_dupl(t_stack *stack);
void	free_stack(t_stack *stack);

int		print_err(void);
void	print_instruct(char inst, char name);

void	sort_stack2(t_stack *stack);
void	sort_stack3(t_stack *stack);
void	sort_stack5(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b, int fl_count);

void	sort_stack(t_stack *a, t_stack *b);
void	create_new_arr(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b, int max_bit);

int		max_in_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		*copy_orig(t_stack *a);
void	quick_sort_arr(int *arr, int n);

#endif
