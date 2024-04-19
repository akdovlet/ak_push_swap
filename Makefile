# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:15:36 by akdovlet          #+#    #+#              #
#    Updated: 2024/04/19 17:10:59 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap
CHECK_NAME	= 	checker
LIBFT 		=	libft/libft.a
PRINTF		=	printf/libftprintf.a

SRCS 		:=	array.c				\
				chechen_sort.c		\
				error_check.c		\
				int.c				\
				intel_gathering.c	\
				jade.c				\
				main.c				\
				parsing.c			\
				push.c				\
				quicksort.c			\
				reverse_rotate.c	\
				rotate.c			\
				solver.c			\
				swap.c
SRCS		:=	$(addprefix source/, $(SRCS))
OBJS		:=	$(patsubst source/%.c, object/%.o,$(SRCS))

BONUS_SRCS	:=	checker.c			\
				checker_utils.c		\
				array.c				\
				chechen_sort.c		\
				error_check.c		\
				int.c				\
				intel_gathering.c	\
				jade.c				\
				parsing.c			\
				push.c				\
				quicksort.c			\
				reverse_rotate.c	\
				rotate.c			\
				solver.c			\
				swap.c
BONUS_SRCS	:=	$(addprefix source/, $(BONUS_SRCS))
BONUS_OBJ	:=	$(patsubst source/%.c, object/%.o,$(BONUS_SRCS))
DEPS		=	$(OBJS:.o=.d)

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -Iinclude -Ilibft/include -Iprintf/include -g3

all: create_dirs $(NAME)

create_dirs:
	@if [ ! -d "object" ]; then mkdir object; fi

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CLFAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(PRINTF):
	@$(MAKE) -C printf

object/%.o: source/%.c
	@printf "\033[0;32%sm\tCompiling: $<\033[0m\r";
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: all $(CHECK_NAME)

$(CHECK_NAME): $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CLFAGS) $(BONUS_OBJ) $(PRINTF) $(LIBFT) -o $(CHECK_NAME)

clean:
	@if [ -d "object" ]; then rm -rf object && echo "\033[1;31mpush_swap .o files have been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory clean -C libft
	@$(MAKE) --no-print-directory clean -C printf

fclean: clean
	@if [ -f "push_swap" ]; then rm -rf push_swap && echo "\033[1;31mpush_swap executable has been deleted\033[0m"; fi
	@if [ -f "checker" ]; then rm -rf checker && echo "\033[1;31mchecker executable has been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory fclean -C libft
	@$(MAKE) --no-print-directory fclean -C printf

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean bonus re 
