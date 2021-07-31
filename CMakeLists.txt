cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap push_swap.c push_swap.h stack_init.c utils/ft_clean.c utils/ft_utils1.c utils/ft_utils2.c
        utils/ft_sort_five.c utils/ft_actions1.c utils/ft_actions2.c utils/ft_actions3.c utils/ft_sort1.c utils/ft_utils3.c utils/ft_sort2.c)