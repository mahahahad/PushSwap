NAME = push_swap
UTILS = ft_putstr.c
CFLAGS = -Wall -Werror -Wextra

all :
	cc $(CFLAGS) -c ft_putstr.c -o ft_putstr.o
	cc $(CFLAGS) push_swap.c ft_putstr.o -o $(NAME)

$(NAME) :

clean :
	@echo "clean rule"

fclean : clean
	@echo "fclean rule"

re : fclean all
