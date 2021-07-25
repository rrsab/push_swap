# include "../push_swap.h"

void ft_free_list(pst_list **list)
{
	pst_list	*l;
	pst_list	*next;

	l = *list;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list = NULL;
}

int	ft_list_dubl_value(pst_list *l, int value)
{
	while (l)
	{
		if (l->value == value)
			return (1);
		l = l->next;
	}
	return (0);
}

int	ft_atoi_new(const char *str, t_heap *heap)
{
	unsigned int	i;
	int				sign;
	int				result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if ((result < 0 && sign == -1) || (result < 0 && sign == 1))
			ft_exit_error(heap);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}