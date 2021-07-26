# include "../push_swap.h"

int ft_check_sort(t_heap *m)
{
	int 		prev;
	pst_list	*l;

	if (!m->a)
		return (1);
	l = m->a;
	prev = l->value;
	while (l)
	{
		if (prev > l->value)
			return (0);
		prev = l->value;
		l = l->next;
	}
	return (1);
}

void ft_sort_list(pst_list **start_list)
{
	pst_list	*last;
	pst_list	*prev;

	prev = NULL;
	last = *start_list;
	while (last && last->next_sort)
	{
		if (last->value - last->next_sort->value > 0)
		{
			if (prev == NULL)
				ft_swap_list(start_list, last);
			else
				ft_swap_list(&(prev->next_sort), last);
			last = *start_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}