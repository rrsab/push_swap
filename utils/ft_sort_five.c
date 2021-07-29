# include "../push_swap.h"

int		ft_find_tag(pst_list *list, int tag)
{
	while (list)
	{
		if (list->ind == tag)
			return (1);
		list = list ->next;
	}
	return (0);
}

void	ft_sort_three_list(t_heap *heap)
{
	pst_list	*a;
	int			m;

	a = heap->a;
	m = heap->max;
	if (m - a->ind == 3 && m - a->next->ind == 1 && m - a->next->next->ind == 2)
	{
		ft_swap_a(heap);
		ft_rotate_a(heap);
	}
	else if (m - a->ind == 2 && m - a->next->ind == 3 && m - a->next->next->ind == 1)
		ft_swap_a(heap);
	else if (m - a->ind == 2 && m - a->next->ind == 1 && m - a->next->next->ind == 3)
		ft_rev_rotate_a(heap);
	else if (m - a->ind == 1 && m - a->next->ind == 3 && m - a->next->next->ind == 2)
		ft_rotate_a(heap);
	else if (m - a->ind == 1 && m - a->next->ind == 2 && m - a->next->next->ind == 3)
	{
		ft_swap_a(heap);
		ft_rev_rotate_a(heap);
	}
	ft_print(heap);
}
void	ft_sort_four_list(t_heap *heap)
{
	pst_list	*a;
	//int			m;
	//pst_list	*start_tag;

	a = heap->a;
	//m = heap->max;
	ft_list_sum(a, heap);
	if (a->next->ind == 0)
		ft_swap_a(heap);
	else if (a->next->next->ind == 0)
	{
		ft_rotate_a(heap);
		ft_rotate_a(heap);
	}
	else if (a->next->next->next->ind == 0)
		ft_rev_rotate_a(heap);
	ft_print(heap);
	ft_push_b(heap);
	ft_sort_three_list(heap);
	ft_push_a(heap);

}

static void	ft_sort_tofive_list(t_heap *heap)
{
	pst_list *a;

	a = heap->a;
	if (a->next->ind == 0)
		ft_swap_a(heap);
	else if (a->next->next->ind == 0)
	{
		ft_rotate_a(heap);
		ft_rotate_a(heap);
	}
	else if (a->next->next->next->ind == 0)
	{
		ft_rev_rotate_a(heap);
		ft_rev_rotate_a(heap);
	}
	else if (a->next->next->next->next->ind == 0)
		ft_rev_rotate_a(heap);
	ft_print(heap);
	ft_push_b(heap);
	ft_sort_four_list(heap);
	ft_push_a(heap);
}

void	ft_sort_five_list(t_heap *heap)
{
	pst_list *a;

	a = heap->a;
	if (heap->max == 2)
		ft_swap_a(heap);
	if (heap->max <= 3)
		ft_sort_three_list(heap);
	if (heap->max == 4)
		ft_sort_four_list(heap);
	if (heap->max == 5)
		ft_sort_tofive_list(heap);
}
