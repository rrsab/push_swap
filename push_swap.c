#include "push_swap.h"

void ft_read_argv(int argc, char **argv, t_heap *heap)
{
	int	i;
	int	j;
	int prev_space;

	i = 0;
	prev_space = 1;
	while (++i < argc)
	{
		prev_space = 1;
		j = -1;
		while (argv[i][++j])
		{
			if(argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
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
void	ft_print(t_heap *heap)
{
	pst_list	*start_tag;

	start_tag = (heap->a);
	printf("\nheap.a = %p max = %d heap.big = %d\n", heap->a, heap->max,
		   heap->big);
	printf("\nheap.group_cnt = %d heap.group_sz = %d \n", heap->group_cnt,
		   heap->group_sz);
	while (start_tag)
	{
		printf("heap.a = %10d ", start_tag->value);
		printf(" heap.a = %10p ", start_tag);
		printf(" heap.a.next = %16p ", start_tag->next);
		printf(" heap.a.next_sort = %16p", start_tag->next_sort);
		printf(" heap.a.ind = %10d \n", start_tag->ind);
		start_tag = start_tag->next;
	}
}

int main(int argc, char **argv)
{
	t_heap		heap;
	pst_list	*start_tag;
//	char 	**tmp;

	heap.a = NULL;
	heap.b = NULL;
	heap.print = 1;
	if (argc <= 1)
		return (write(1, "\n", 1));
	ft_read_argv(argc, argv, &heap);

	if (!ft_check_sort(&heap))
	{
		start_tag = (heap.a);
		ft_sort_list(&start_tag);
		ft_list_sum(start_tag, &heap);
		if (heap.max <= 5)
			ft_sort_five_list(&heap);
		ft_main_sort(&heap, 1);
//		нужно написать функции ft_list_sort
//		tag_list
	}
	start_tag = (heap.a);
	//tmp = argv;

	ft_print(&heap);

//	printf("\nheap.a = %p max = %d \n", heap.a, heap.max);
//	while (start_tag)
//	{
//		printf("heap.a = %10d ", start_tag->value);
//		printf(" heap.a = %10p ", start_tag);
//		printf(" heap.a.next = %16p ", start_tag->next);
//		printf(" heap.a.next_sort = %16p", start_tag->next_sort);
//		printf(" heap.a.ind = %10d \n", start_tag->ind);
//		start_tag = start_tag->next;
//	}
	//printf("heap.a = %d \n", start_tag->value);
	ft_clear_all(&heap);
	start_tag = NULL;
	return 0;
}
