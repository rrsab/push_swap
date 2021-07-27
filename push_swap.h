#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct pss_list
{
	int				value;
	int				index;
	int 			keep;
	struct pss_list	*next;
	struct pss_list	*next_sort;
}					pst_list;

typedef struct s_heap
{
	pst_list 			*a;
	pst_list 			*b;
	int 			max;
	int 			big;
	int 			size;
	int 			group_cnt;
	int				group_sz;
	int 			print;
	pst_list			*temp;
	int 			action_count;
}					t_heap;

void	ft_clear_all(t_heap *heap);
void	ft_read_argv(int argc, char **argv, t_heap *heap);
void 	ft_exit_error(t_heap *heap);
void	ft_free_list(pst_list **list);
int		ft_list_dubl_value(pst_list *l, int value);
void	ft_stack_init(pst_list **stack, int value, int tag, t_heap *heap);
int		ft_atoi_new(const char *str, t_heap *heap);
int		ft_check_sort(t_heap *m);
void	ft_sort_list(pst_list **start_list);
void    ft_swap_list(pst_list **prevnext, pst_list *last);

#endif
