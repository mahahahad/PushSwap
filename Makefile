NAME = push_swap
UTILS = ft_putstr.c
CFLAGS = -Wall -Werror -Wextra
LIBFT = Libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT)
	cc $(CFLAGS) push_swap.c $< -o $(NAME)

$(LIBFT) :
	make -C Libft/

clean :
	@make clean -C Libft/

fclean : clean
	@make fclean -C Libft/

re : fclean all

.PHONY : all $(NAME) $(LIBFT) clean fclean re
