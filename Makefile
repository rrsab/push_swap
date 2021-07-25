NAME	= push_swap

BONUS	= push_swap_bonus

SRCS	= push_swap.c stack.c utils/ft_clean.c utils/ft_utils1.c

SRCS_B	=

OBJS	= $(patsubst %.c, %.o, $(SRCS))

OBJS_B	= $(patsubst %.c, %.o, $(SRCS_B))

CC		= gcc

RM		= rm -f

HEADER	= push_swap.h

HEAD_B	=

CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRCS)	libft/libft.a $(HEADER)
			@make -C libft
			$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

$(BONUS):	$(SRCS_B)	libft/libft.a $(HEAD_B)
			@make -C libft
			$(CC) $(CFLAGS) $(SRCS_B) libft/libft.a -o $(BONUS)

bonus:		$(BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_B)
			@$(MAKE) clean -C ./libft/

fclean:		clean
			$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus