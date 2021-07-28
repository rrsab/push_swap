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
void	ft_swap_list(pst_list **prevnext, pst_list *last);
void	ft_list_sum(pst_list *start, t_heap *heap);
int		ft_find_tag(pst_list *list, int tag);
void	ft_sort_five_list(t_heap *mem);
void	ft_swap(pst_list **stack);
void	ft_push_x1_in_x2(pst_list **x1, pst_list **x2);
void	ft_swap_a(t_heap *heap);
void	ft_swap_b(t_heap *heap);
void	ft_swap_ss(t_heap *heap);
void	ft_push_a(t_heap *heap);
void	ft_push_b(t_heap *heap);
void	ft_put_top_to_bottom(pst_list **x);
void	ft_put_bottom_to_top(pst_list **x);
void	ft_rev_rotate_a(t_heap *heap);
void	ft_rev_rotate_b(t_heap *heap);
void	ft_rev_rotate_a_b(t_heap *heap);
void	ft_rotate_a(t_heap *heap);
void	ft_rotate_b(t_heap *heap);
void	ft_rotate_a_b(t_heap *heap);
void	ft_sort_three_list(t_heap *heap);
void	ft_sort_five_list(t_heap *heap);

#endif
