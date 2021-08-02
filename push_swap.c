/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:08:50 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 22:08:52 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read_argv(int argc, char **argv, t_heap *heap)
{
	int	i;
	int	j;
	int	prev_space;

	i = 0;
	prev_space = 1;
	while (++i < argc)
	{
		prev_space = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
				&& !ft_isdigit(argv[i][j]))
				ft_exit_error(heap);
			if (prev_space == 1 && argv[i][j] != ' ')
			{
				ft_stack_init(&(heap->a), ft_atoi_new(argv[i] + j, heap), -1,
					heap);
				prev_space = 0;
			}
			prev_space = argv[i][j] == ' ';
		}
	}
}

int	main(int argc, char **argv)
{
	t_heap		heap;
	t_pslist	*start_tag;

	heap.a = NULL;
	heap.b = NULL;
	if (argc <= 1)
		exit(EXIT_SUCCESS);
	ft_read_argv(argc, argv, &heap);
	if (!ft_check_sort(&heap))
	{
		start_tag = (heap.a);
		ft_sort_list(&start_tag);
		ft_list_ind_max(start_tag, &heap);
		if (heap.max <= 5)
			ft_sort_five_list(&heap);
		else
			ft_main_sort(&heap, 1);
	}
	ft_clear_all(&heap);
	start_tag = NULL;
	return (0);
}
