# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira <avieira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 11:51:16 by avieira           #+#    #+#              #
#    Updated: 2021/09/27 16:44:56 by avieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_PS = push_swap

CC = clang

MKD = mkdir

RM = rm -rf

SRCS =	sources/utils/ft_atoi_of.c \
		sources/get_stack.c \
		sources/get_opes.c \
		sources/opes/sa.c \
		sources/opes/sb.c \
		sources/opes/ss.c \
		sources/opes/pa.c \
		sources/opes/pb.c \
		sources/opes/ra.c \
		sources/opes/rb.c \
		sources/opes/rr.c \
		sources/opes/rra.c \
		sources/opes/rrb.c \
		sources/opes/rrr.c \
		sources/opes/exec_opes/push.c \
		sources/opes/exec_opes/rotate.c \
		sources/opes/exec_opes/swap.c \
		sources/check_stacks.c \
		sources/exec_opes.c \
		sources/alloc_free.c \
		sources/utils/transform_stack.c

SRC_CHECKER = sources/checker.c
SRC_PUSH_SWAP = sources/push_swap.c

OBJ = $(SRCS:%.c=%.o)
OBJ_CHECKER = $(SRC_CHECKER:%.c=%.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=%.o)

IFLAGS = ./includes/

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = sources/

LIBFT = -L sources/libft -lft

STRT_STYLE = \033[1;32m

END_STYLE = \033[0m

all: $(NAME_C) $(NAME_PS)

%.o: %.c
	@($(CC) $(CFLAGS) -c -I$(IFLAGS) $< -o $(<:.c=.o))

checker: $(OBJ) $(OBJ_CHECKER)
	@(printf "$(STRT_STYLE)Compiling libft...\n$(END_STYLE)")
	@make -C sources/libft/
	@(printf "$(STRT_STYLE)Compiling...\n$(END_STYLE)")
	@($(CC) -o $(NAME_C) -I$(IFLAGS) $^ $(CFLAGS) $(LIBFT))
	@(printf "$(STRT_STYLE)Done.\n$(END_STYLE)")

push_swap: $(OBJ) $(OBJ_PUSH_SWAP)
	@(printf "$(STRT_STYLE)Compiling libft...\n$(END_STYLE)")
	@make -C sources/libft/
	@(printf "$(STRT_STYLE)Compiling...\n$(END_STYLE)")
	@($(CC) -o $(NAME_PS) -I$(IFLAGS) $^ $(CFLAGS) $(LIBFT))
	@(printf "$(STRT_STYLE)Done.\n$(END_STYLE)")

clean:
	@(printf "$(STRT_STYLE)Cleaning libft...\n$(END_STYLE)")
	@make clean -C sources/libft/
	@(printf "$(STRT_STYLE)Cleaning...\n$(END_STYLE)")
	@($(RM) $(SRCS_DIR)/*.o)
	@($(RM) $(SRCS_DIR)/*/*.o)
	@($(RM) $(SRCS_DIR)/*/*/*.o)
	@(printf "$(STRT_STYLE)Done.\n$(END_STYLE)")

fclean: clean
	@(printf "$(STRT_STYLE)Fcleaning libft...\n$(END_STYLE)")
	@make fclean -C sources/libft/
	@(printf "$(STRT_STYLE)Fcleaning...\n$(END_STYLE)")
	@($(RM) $(NAME_C))
	@($(RM) $(NAME_PS))
	@(printf "$(STRT_STYLE)Done.\n$(END_STYLE)")

re: fclean all

.PHONY: all clean fclean re
