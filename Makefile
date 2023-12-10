# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 12:10:43 by alex              #+#    #+#              #
#    Updated: 2023/12/08 17:42:26 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fract-ol
FLAGS	= 	-Wall -Wextra -Werror
CC		=	cc
FILES	=	main \
			mandelbrot \
			print_mandelbrot
HEADERS	=	fractal.h \
			./ft_printf/ft_printf.h \
			./libft/libft.h
OBJS	= 	$(addsuffix .o, $(FILES))
SRCS	= 	$(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME): $(OBJS) libft libftprintf
	$(CC) $(FLAGS) -Ift_printf/ -Ilibft/ -o $(NAME) $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a

libft:
	make -C libft re

libftprintf:
	make -C ft_printf re

%.o : %.c 
	$(CC) $(FLAGS) -Ift_printf/ -Ilibft/ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re