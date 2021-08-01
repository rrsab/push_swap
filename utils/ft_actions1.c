/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:18:15 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:18:19 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_pslist **stack)
{
	t_pslist	*temp;
	t_pslist	*next_list;

	if (!*stack || !(*stack)->next)
		return ;
	next_list = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = next_list;
}

void	ft_push_x1_in_x2(t_pslist **x1, t_pslist **x2)
{
	t_pslist	*tmp;

	if (!*x1)
		return ;
	tmp = *x1;
	*x1 = tmp->next;
	if (*x2)
		tmp->next = (*x2);
	else
		tmp->next = NULL;
	*x2 = tmp;
}

void	ft_put_top_to_bottom(t_pslist **x)
{
	t_pslist	*top;
	t_pslist	*tmp;

	if (!*x || !(*x)->next)
		return ;
	top = *x;
	*x = (*x)->next;
	tmp = *x;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
	top->next = NULL;
}

void	ft_put_bottom_to_top(t_pslist **x)
{
	t_pslist	*last;
	t_pslist	*prev;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*x);
	*x = last;
	prev->next = NULL;
}

void	ft_rotate_a_b(t_heap *heap)
{
	ft_put_top_to_bottom(&(heap->a));
	ft_put_top_to_bottom(&(heap->b));
	ft_putstr_fd("rr\n", 1);
}
