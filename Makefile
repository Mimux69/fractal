# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 12:10:43 by alex              #+#    #+#              #
#    Updated: 2023/12/13 17:36:07 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
FLAGS	=	-Wall -Wextra -Werror 
MLFLAGS	=	-LX11 -LXext -Lmlx -Lm -lX11 -lXext -lm
CC		=	cc
FILES	=	main \
			mandelbrot \
			julia \
			ft_atod \
			input \
			color \
			burning_ship \
			buddhabrot
HEADERS	=	-Ift_printf/ -Ilibft/ -Iminilibx-linux
LIBS	=	./libft/libft.a ./ft_printf/libftprintf.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
OBJS	= 	$(addsuffix .o, $(FILES))
SRCS	= 	$(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME): libft.a libftprintf.a
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(HEADERS) $(LIBS) $(MLFLAGS)

libft.a:
	make -C libft re

libftprintf.a:
	make -C ft_printf re

%.o : %.c 
	$(CC) $(FLAGS) $(MLFLAGS) -Ift_printf/ -Ilibft/ -Iminilibx-linux minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -LX11 -LXext -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re