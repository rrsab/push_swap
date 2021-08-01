/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:16:59 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:17:01 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_heap *heap)
{
	ft_swap(&(heap->a));
	ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(t_heap *heap)
{
	ft_swap(&(heap->b));
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_ss(t_heap *heap)
{
	ft_swap(&(heap->a));
	ft_swap(&(heap->b));
	ft_putstr_fd("ss\n", 1);
}

void	ft_push_a(t_heap *heap)
{
	ft_push_x1_in_x2(&(heap->b), &(heap->a));
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_heap *heap)
{
	ft_push_x1_in_x2(&(heap->a), &(heap->b));
	ft_putstr_fd("pb\n", 1);
}
