NAME	= push_swap

SRCS	= push_swap.c stack_init.c utils/ft_clean.c utils/ft_utils1.c utils/ft_utils2.c utils/ft_utils3.c\
		utils/ft_sort_five.c\
		utils/ft_sort1.c utils/ft_sort2.c utils/ft_sort3.c\
		utils/ft_actions1.c utils/ft_actions2.c utils/ft_actions3.c\

OBJS	= $(patsubst %.c, %.o, $(SRCS))

OBJS_B	= $(patsubst %.c, %.o, $(SRCS_B))

CC		= gcc

RM		= rm -f

HEADER	= push_swap.h

CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRCS) $(HEADER)
			@make -C libft
			$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_B)
			@$(MAKE) clean -C ./libft/

fclean:		clean
			$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all clean fclean re