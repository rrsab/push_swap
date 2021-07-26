cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap push_swap.c push_swap.h utils/ft_clean.c utils/ft_utils1.c utils/ft_utils2.c stack.c)