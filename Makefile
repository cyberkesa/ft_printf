# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwinfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:04:48 by vwinfred          #+#    #+#              #
#    Updated: 2021/01/14 19:17:23 by vwinfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=		ft_printf.c \
			pf_s.c \
			pf_di.c \
			pf_utils.c
OBJECTS=	$(patsubst %.c, %.o, $(SRCS))
INCLUDES= 	./inc

#CFLAGS = -Wall -Wextra -Werror

CC= gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ./Libft re
	@ar -rcs $(NAME) $(OBJECTS) ./Libft/objects/*.o
	@ranlib $(NAME)
%.o:%.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
clean:
	@make -C ./Libft clean
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C ./Libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(NAME) -L Libft -lft main.c -o test

.PHONY: clean fclean all re test
