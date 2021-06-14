NAME = libftprintf.a

SOURCES = ./srcs/ft_printf.c ./srcs/ft_printf_utils.c ./srcs/ft_printf_utils2.c \
./srcs/ft_printf_utils3.c ./srcs/ft_printf_utils4.c ./srcs/ft_printf_utils5.c \
./srcs/ft_printf_utils6.c ./srcs/ft_printf_utils7.c

OBJECTS = $(SOURCES:%.c=%.o)


.c.o:
	gcc -c -Wall -Wextra -Werror -I -c $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) libft.a -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJECTS)

all: $(NAME)

bonus:

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean flcean re
