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

void	ft_sort_five_list(t_heap *heap)
{
	pst_list	*l;
	int			min;
	int			curr;

	while (ft_find_tag(heap->a, 0) || ft_find_tag(heap->a, heap->max - 1))
	{
		l = heap->a;
		min = 999;
		while ()
	}
}
