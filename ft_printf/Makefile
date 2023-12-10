# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acronert <acronert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:48:25 by acronert          #+#    #+#              #
#    Updated: 2023/11/16 15:42:30 by acronert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a
FLAGS	= 	-Wall -Wextra -Werror
SRCS	=	printf \
			printf_utils \
			printf_types \
			printf_types_2
HEAD	= 	ft_printf.h
OBJS	= 	$(addsuffix .o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

libft.a: $(LIB_OBJS)
	ar rcs libft.a $(LIB_OBJS)

%.o : %.c 
	cc $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@cc $(FLAGS) -I./includes main.c $(NAME) 
	@./a.out

.PHONY: all clean fclean re
