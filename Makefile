# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabdull <maabdull@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 11:31:41 by maabdull          #+#    #+#              #
#    Updated: 2024/01/02 11:51:31 by maabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
LIBFT = Libft/libft.a

all : $(NAME)

debug : CFLAGS += -g
debug : re

$(NAME) : $(LIBFT)
	@cc $(CFLAGS) push_swap.c operations.c $< -o $(NAME)
	@echo "Created push_swap!"

$(LIBFT) :
	@make -C Libft/

clean :
	@make clean -C Libft/

fclean : clean
	@make fclean -C Libft/

re : fclean all

.PHONY : all $(NAME) $(LIBFT) clean fclean re
