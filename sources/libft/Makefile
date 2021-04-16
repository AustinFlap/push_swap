# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira <avieira@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:48:43 by avieira           #+#    #+#              #
#    Updated: 2021/04/16 16:30:21 by avieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= INT_STR/ft_atoi.c MEM/ft_bzero.c MEM/ft_calloc.c CHAR/ft_isalnum.c \
			CHAR/ft_isalpha.c CHAR/ft_isdigit.c CHAR/ft_isprint.c \
			INT_STR/ft_itoa.c MEM/ft_memccpy.c MEM/ft_memchr.c  \
			MEM/ft_memcpy.c MEM/ft_memmove.c MEM/ft_memset.c \
			PUT_FD/ft_putstr_fd.c STR/ft_strlcat.c STR/ft_strnstr.c \
			STR/ft_strjoin.c PUT_FD/ft_putnbr_fd.c STR/ft_strtrim.c \
			STR/ft_strmapi.c STR/ft_strncmp.c CHAR/ft_tolower.c \
			STR/ft_strrchr.c PUT_FD/ft_putchar_fd.c STR/ft_strlen.c \
			STR/ft_split.c STR/ft_strchr.c STR/ft_strdup.c STR/ft_strlcpy.c \
			STR/ft_substr.c PUT_FD/ft_putendl_fd.c CHAR/ft_isascii.c \
			MEM/ft_memcmp.c CHAR/ft_toupper.c LST/ft_lstadd_back.c \
			LST/ft_lstadd_front.c LST/ft_lstclear.c LST/ft_lstdelone.c \
			LST/ft_lstiter.c LST/ft_lstlast.c LST/ft_lstmap.c LST/ft_lstnew.c \
			LST/ft_lstsize.c GNL/get_next_line.c \
			GNL/get_next_line_utils.c PRINTF/conversion.c \
			PRINTF/conversion_2.c PRINTF/flags.c PRINTF/ft_printf.c \
			PRINTF/printf_utils.c PRINTF/printf_utils_2.c 

CC		= clang
RM		= rm -f
NAME	= libft.a
CTFLAGS	= -Wall -Werror -Wextra -I./includes

OBJS	= ${SRCS:.c=.o}

$(NAME):	${OBJS}
			@ar rc ${NAME} $^
			@ranlib ${NAME}

all:	$(NAME)

%.o: %.c
			@$(CC) $(CTFLAGS) -c $< -o $@

clean: 
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re

