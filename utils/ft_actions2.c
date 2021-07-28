# include "../push_swap.h"

void	ft_swap_a(t_heap *heap)
{
	ft_swap(&(heap->a));
	ft_putstr_fd("sa", 1);
}

void	ft_swap_b(t_heap *heap)
{
	ft_swap(&(heap->b));
	ft_putstr_fd("sb", 1);
}

void	ft_swap_ss(t_heap *heap)
{
	ft_swap(&(heap->a));
	ft_swap(&(heap->b));
	ft_putstr_fd("ss", 1);
}

void	ft_push_a(t_heap *heap)
{
	ft_push_x1_in_x2(&(heap->b), &(heap->a));
	ft_putstr_fd("pa", 1);
}

void	ft_push_b(t_heap *heap)
{
	ft_push_x1_in_x2(&(heap->a), &(heap->b));
	ft_putstr_fd("pb", 1);
}
