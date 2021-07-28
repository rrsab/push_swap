# include "../push_swap.h"

void	ft_rev_rotate_a(t_heap *heap)
{
	ft_put_bottom_to_top(&(heap->a));
	ft_putstr_fd("rra", 1);
}

void	ft_rev_rotate_b(t_heap *heap)
{
	ft_put_bottom_to_top(&(heap->b));
	ft_putstr_fd("rrb", 1);
}

void	ft_rev_rotate_a_b(t_heap *heap)
{
	ft_put_bottom_to_top(&(heap->a));
	ft_put_bottom_to_top(&(heap->b));
	ft_putstr_fd("rrr", 1);
}

void	ft_rotate_a(t_heap *heap)
{
	ft_put_top_to_bottom(&(heap->a));
	ft_putstr_fd("ra", 1);
}

void	ft_rotate_b(t_heap *heap)
{
	ft_put_top_to_bottom(&(heap->b));
	ft_putstr_fd("rb", 1);
}