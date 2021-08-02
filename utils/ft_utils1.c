/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:03:37 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:04:00 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_pslist **list)
{
	t_pslist	*l;
	t_pslist	*next;

	l = *list;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list = NULL;
}

int	ft_list_dubl_value(t_pslist *l, int value)
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
	long			result;

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
		result = result * 10 + (str[i] - '0');
		if ((result > 2147483648 && sign == -1) || (result > 2147483647 &&
		sign == 1))
		{
			ft_exit_error(heap);
		}
		i++;
	}
	return ((int)(sign * result));
}
