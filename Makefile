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

NAME = libftprintf.a

LIBFT = ./Libft/libft.a

OBJD = objects/

SRCS =		ft_printf.c \
			pf_s.c \
			pf_di.c \
			pf_utils.c\
			pf_px.c \
			pf_parce.c \
			pf_ucpr.c \
			pf_itoa.c

OBJECTS =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRCS)))

INCLUDES = 	./inc

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME):: $(LIBFT)
$(NAME):: $(OBJD) $(OBJECTS)
	@cp $(LIBFT) .
	@ar -rc $(notdir $(LIBFT)) $(OBJECTS)
	@mv $(notdir $(LIBFT)) $(NAME)
	@ranlib $(NAME)
	@printf "\x1b[7m Create: "
	@printf $@
	@printf "\x1b[7m\n"

$(LIBFT):
	@make -C ./Libft

$(OBJD)%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@
	@printf "\x1b[2m\x1b[m Compile object: "
	@printf $(notdir $@)
	@printf "\x0b\n"

$(OBJD):
	@mkdir -p objects

clean:
	@make clean -C ./Libft
	@rm -rf $(OBJD)

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test

.PHONY: clean fclean all re test
