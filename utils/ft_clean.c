/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:16:03 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:16:05 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clear_all(t_heap *heap)
{
	ft_free_list(&(heap->a));
	ft_free_list(&(heap->b));
}

void	ft_exit_error(t_heap *heap)
{
	ft_putendl_fd("Error", 2);
	ft_clear_all(heap);
	exit(EXIT_FAILURE);
}
