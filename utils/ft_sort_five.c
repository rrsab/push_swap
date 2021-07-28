# include "../push_swap.h"

int		ft_find_tag(pst_list *list, int tag)
{
	while (list)
	{
		if (list->index == tag)
			return (1);
		list = list ->next;
	}
	return (0);
}

void	ft_sort_three_list(t_heap *heap)
{
	pst_list *a;

	a = heap->a;
	if (a->index == 0 && a->next->index == 2 && a->next->next->index == 1)
	{
		ft_swap_a(heap);
		ft_push_a(heap);
	}
	if (a->index == 1 && a->next->index == 0 && a->next->next->index == 2)
		ft_swap_a(heap);
	if (a->index == 1 && a->next->index == 2 && a->next->next->index == 0)
		ft_rev_rotate_a(heap);
	if (a->index == 2 && a->next->index == 0 && a->next->next->index == 1)
		ft_rotate_a(heap);
	if (a->index == 2 && a->next->index == 1 && a->next->next->index == 0)
	{
		ft_swap_a(heap);
		ft_rev_rotate_a(heap);
	}
}

void	ft_sort_five_list(t_heap *heap)
{
	ft_sort_three_list(heap);
}
