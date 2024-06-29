# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 14:50:34 by esozbalt          #+#    #+#              #
#    Updated: 2024/02/08 14:50:37 by esozbalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_printf_utils.c \

OBJS	=	$(SRCS:.c=.o)

CC	= gcc
RM	= rm -f
FLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	
			$(CC) $(FLAGS) -c $(SRCS)
			ar -rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:	clean
					$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re