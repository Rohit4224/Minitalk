# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:14:53 by rkhinchi          #+#    #+#              #
#    Updated: 2022/11/13 16:15:00 by rkhinchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libftprintf.a

HEADER		= libftprintf.h

SOURCES		:= integer_i_d.c \
		character_c.c \
		ft_printf.c \
		hexadecimal_x.c \
		string_s.c \
		unsigned_integer_u.c \
		hexadecimal_p.c \

OBJECTS		= $(SOURCES:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

CC		= gcc

all		: $(NAME)

$(NAME)		: $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

%.o:%.c
		$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY :=	fclean re all clean
