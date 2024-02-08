# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:58:57 by maabdull          #+#    #+#              #
#    Updated: 2024/02/01 21:08:13 by maabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -g3

SRCS = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_issign.c ft_isspace.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_strcmp.c ft_substr.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $^
	@echo "\nArchive file created"

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@cc $(FLAGS) -c $< -o $@
	@echo ".\c"

test : re
	cc $(FLAGS) $(NAME) main.c -o test
	@echo "Output of test file is: "
	@./test

clean :
	@rm -rf $(OBJ_DIR)
	@echo "Removed all object files"

fclean : clean
	@rm -rf *.o test
	@rm -f $(NAME)
	@echo "Removed all unneccessary files"

re : fclean all

# Make the bonus object files first.
# Add these files to the archive
bonus : $(NAME) $(BONUS_OBJS)
	@echo "Adding bonus files"
	@ar rv $(NAME) $(BONUS_OBJS)

.PHONY : all clean fclean re
