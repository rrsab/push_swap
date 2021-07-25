#include "../push_swap.h"

void	ft_clear_all(t_heap *heap)
{
	ft_free_list(&(heap->a));
	ft_free_list(&(heap->b));
}

void 	ft_exit_error(t_heap *heap)
{
	ft_putendl_fd("Error", 2);
	ft_clear_all(heap);
	exit(EXIT_FAILURE);
}