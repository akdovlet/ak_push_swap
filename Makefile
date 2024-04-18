# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:15:36 by akdovlet          #+#    #+#              #
#    Updated: 2024/04/18 13:53:44 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	push_swap

LIBFT 	=	libft/libft.a
PRINTF	=	printf/libftprintf.a

SRCS 	:=	parsing.c	\
			main.c		\
			swap.c		\
			push.c		\
			rotate.c	\
			reverse_rotate.c	\
			array.c				\
			quicksort.c			\
			error_check.c		\
			print_array.c		\
			indexing.c			\
			solver.c			\
			int.c				\
			ataturk.c			\
			jade.c				\
			chechen_sort.c		\
			intel_gathering.c	\
			targeting.c
SRCS	:=	$(addprefix source/, $(SRCS))
OBJS	:=	$(patsubst source/%.c, object/%.o,$(SRCS))
DEPS	:=	$(OBJS:.o=.d)

CC		=	cc
CFLAGS	=	-MMD -MP -Iinclude -Ilibft/include -Iprintf/include -g3

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
	@printf "\033[0;32%sm\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "object" ]; then rm -rf object && echo "\033[1;31mpush_swap .o files have been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory clean -C libft
	@$(MAKE) --no-print-directory clean -C printf

fclean: clean
	@if [ -f "push_swap" ]; then rm -rf push_swap && echo "\033[1;31mpush_swap executable has been deleted\033[0m"; fi
	@$(MAKE) --no-print-directory fclean -C libft
	@$(MAKE) --no-print-directory fclean -C printf

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean
