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
	start_tag = (heap.a);
	//tmp = argv;
	printf("Hello, World!\n");
	while (start_tag->next)
	{
		printf("heap.a = %d \n", start_tag->value);
		start_tag = start_tag->next;
	}
	printf("heap.a = %d \n", start_tag->value);
	return 0;
}
