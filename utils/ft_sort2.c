# include "../push_swap.h"

int	ft_distance_to_top(pst_list *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = ft_list_size(a);
	while (a)
	{
		if (a->ind == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}


pst_list	*ft_closest_in_group(pst_list *list, int cur_group, int group_sz)
{
	pst_list	*closest;
	pst_list	*cur;
	int		distance;
	int		cur_dist;

	distance = 0xFFFFFFF;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->ind <= group_sz * cur_group && !cur->keep)
		{
			cur_dist = ft_distance_to_top(list, cur->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}
