/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:03:29 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 22:03:37 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_pslist
{
	int				value;
	int				ind;
	int				keep;
	struct s_pslist	*next;
	struct s_pslist	*next_sort;
}					t_pslist;

typedef struct s_heap
{
	t_pslist	*a;
	t_pslist	*b;
	int			max;
	int			big;
	int			size;
	int			group_cnt;
	int			group_sz;
	int			print;
	t_pslist	*temp;
	int			action_count;
}				t_heap;

void		ft_print(t_heap *heap);

void		ft_clear_all(t_heap *heap);
void		ft_read_argv(int argc, char **argv, t_heap *heap);
void		ft_exit_error(t_heap *heap);
void		ft_free_list(t_pslist **list);
int			ft_list_dubl_value(t_pslist *l, int value);
void		ft_stack_init(t_pslist **stack, int value, int tag, t_heap *heap);
int			ft_atoi_new(const char *str, t_heap *heap);
int			ft_check_sort(t_heap *m);
void		ft_sort_list(t_pslist **start_list);
void		ft_swap_list(t_pslist **prevnext, t_pslist *last);
void		ft_list_sum(t_pslist *start, t_heap *heap);
int			ft_find_tag(t_pslist *list, int tag);

void		ft_swap(t_pslist **stack);
void		ft_push_x1_in_x2(t_pslist **x1, t_pslist **x2);
void		ft_swap_a(t_heap *heap);
void		ft_swap_b(t_heap *heap);
void		ft_swap_ss(t_heap *heap);
void		ft_push_a(t_heap *heap);
void		ft_push_b(t_heap *heap);
void		ft_put_top_to_bottom(t_pslist **x);
void		ft_put_bottom_to_top(t_pslist **x);
void		ft_rev_rotate_a(t_heap *heap);
void		ft_rev_rotate_b(t_heap *heap);
void		ft_rev_rotate_a_b(t_heap *heap);
void		ft_rotate_a(t_heap *heap);
void		ft_rotate_b(t_heap *heap);
void		ft_rotate_a_b(t_heap *heap);
void		ft_sort_three_list(int m, t_heap *heap);
void		ft_sort_five_list(t_heap *heap);
void		ft_sort_four_list(int m, t_heap *heap);

//global sort

int			ft_loop_list(t_pslist *list, t_pslist *start, int set);
int			ft_find_biggest_loop(t_pslist *start, int set);
int			ft_list_size(t_pslist *l);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
void		ft_init_sort(t_heap *heap);
void		ft_main_sort(t_heap *heap, int cur_group);
int			ft_abs(int a);
int			ft_distance_to_top(t_pslist *a, int tag);
t_pslist	*ft_closest_in_group(t_pslist *list, int cur_group, int group_sz);
int			ft_can_swap(t_pslist *list);
void		ft_double_rotate(t_heap *heap, int *rot_a, int *rot_b);
void		ft_rotate(t_heap *heap, int rot_a, int rot_b);
int			ft_distance_to_tag(int tag, int size);
t_pslist	*ft_get_last(t_pslist *l);
int			ft_insert_distance(t_pslist *list, int t, int size);
void		ft_return_a(t_heap *heap);

#endif
