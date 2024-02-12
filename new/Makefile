# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 21:44:39 by maabdull          #+#    #+#              #
#    Updated: 2024/02/11 22:51:16 by maabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c
LIBFT = ../Libft/libft.a
NAME = push_swap
FLAGS = -Wall -Werror -Wextra -g
SRCS = sort_five.c sort_radix.c sort_three.c sort_utils.c stack.c stack_utils.c utils.c operations.c args_valid.c args_parse.c
OBJS_DIR = objects/
OBJS =$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
MAIN = shmain.c

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) $(LIBFT) $(MAIN) -o $(NAME)

$(LIBFT):
	make -C ../Libft/

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	cc $(FLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

.PHONY: $(NAME) all fclean clean re
