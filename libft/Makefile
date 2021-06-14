# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhasegaw <rhasegaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 20:26:36 by rhasegaw          #+#    #+#              #
#    Updated: 2021/04/15 18:01:03 by rhasegaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = -I./

SRCS = ft_isalpha.c ft_atoi.c ft_strncmp.c \
ft_strlcat.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
ft_strjoin.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strmapi.c \
ft_strtrim.c ft_split.c

BONUS_SRCS = ft_isalpha.c ft_atoi.c ft_strncmp.c \
ft_strlcat.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
ft_strjoin.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strmapi.c \
ft_strtrim.c ft_split.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

.c.o:
	gcc -c -Wall -Wextra -Werror $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
