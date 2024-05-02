# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 16:15:36 by akdovlet          #+#    #+#              #
#    Updated: 2024/05/02 20:39:20 by akdovlet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap
BONUS_NAME	= 	checker
LIBDIR		= 	lib
LIBFT 		=	$(LIBDIR)/libft/libft.a
BUILD		:=	.build
SRCDIR		:=	src

SRCS 		:=	array.c				\
				chechen_sort.c		\
				error_check.c		\
				int.c				\
				intel_gathering.c	\
				jade.c				\
				lst_functions.c		\
				main.c				\
				parsing.c			\
				push.c				\
				quicksort.c			\
				reverse_rotate.c	\
				rotate.c			\
				solver.c			\
				swap.c
SRCS		:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS		:=	$(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o,$(SRCS))

BONUS_SRCS	:=	checker.c			\
				checker_utils.c		\
				array.c				\
				chechen_sort.c		\
				error_check.c		\
				int.c				\
				intel_gathering.c	\
				jade.c				\
				lst_functions.c		\
				parsing.c			\
				push.c				\
				quicksort.c			\
				reverse_rotate.c	\
				rotate.c			\
				solver.c			\
				swap.c
BONUS_SRCS	:=	$(addprefix $(SRCDIR)/, $(BONUS_SRCS))
BONUS_OBJ	:=	$(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o,$(BONUS_SRCS))
DEPS		=	$(OBJS:.o=.d)

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MMD -MP -Iinclude -I$(LIBDIR)/libft/include -g3

all: create_dirs $(NAME)

create_dirs:
	@if [ ! -d "$(BUILD)" ]; then mkdir $(BUILD); fi

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)/libft

$(BUILD)/%.o: $(SRCDIR)/%.c
	@printf "\033[1;32%sm\tCompiling: $<\033[0m\n";
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs $(BONUS_NAME)

both: all bonus

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(PRINTF) $(LIBFT) -o $(BONUS_NAME)

clean:
	@if [ -d "$(BUILD)" ]; then $(RM) -rf $(BUILD) && echo "\033[9;31m\t$(NAME) $(BUILD)\033[0m"; fi
	@$(MAKE) --no-print-directory clean -C $(LIBDIR)/libft

fclean: clean
	@if [ -f "$(NAME)" ]; then $(RM) -rf $(NAME) && echo "\033[9;31m\t$(NAME)\033[0m"; fi
	@if [ -f "$(BONUS_NAME)" ]; then $(RM) -rf $(BONUS_NAME) && echo "\033[9;31m\t$(BONUS_NAME)\033[0m"; fi
	@$(MAKE) --no-print-directory fclean -C $(LIBDIR)/libft

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean bonus re both
