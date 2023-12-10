# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acronert <acronert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 17:55:24 by acronert          #+#    #+#              #
#    Updated: 2023/11/08 18:26:14 by acronert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ./
CFLAGS = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ./ft_isprint.c ./ft_putendl_fd.c ./ft_strlcat.c ./ft_substr.c \
./ft_atoi.c ./ft_itoa.c ./ft_putnbr_fd.c ./ft_strlcpy.c ./ft_tolower.c \
./ft_bzero.c ./ft_memchr.c ./ft_putstr_fd.c ./ft_strlen.c ./ft_toupper.c \
./ft_calloc.c ./ft_memcmp.c ./ft_split.c ./ft_strmapi.c ./libft.h \
./ft_isalnum.c ./ft_memcpy.c ./ft_strchr.c ./ft_strncmp.c ./ft_isalpha.c \
./ft_memmove.c ./ft_strdup.c ./ft_strnstr.c ./ft_isascii.c ./ft_memset.c \
./ft_striteri.c ./ft_strrchr.c ./ft_isdigit.c ./ft_putchar_fd.c \
./ft_strjoin.c ./ft_strtrim.c
SRC_BONUS = ./ft_lstnew.c \
./ft_lstadd_front.c \
./ft_lstsize.c \
./ft_lstlast.c \
./ft_lstadd_back.c \
./ft_lstdelone.c \
./ft_lstclear.c \
./ft_lstiter.c \
./ft_lstmap.c
OBJ = *.o

all: $(NAME)

$(NAME):
	cc $(CFLAGS) $(OPTION) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	cc $(CFLAGS) $(OPTION) $(SRC) $(SRC_BONUS)
	ar rc $(NAME) $(OBJ)

so:
	cc -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRC_BONUS)
	cc -nostartfiles -shared -o libft.so $(OBJ)
