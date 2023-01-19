# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 20:55:44 by astachni          #+#    #+#              #
#    Updated: 2022/12/30 16:11:20 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRCS = ft_printf.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/print_func.c src/ft_itoa.c src/ft_itoa_u.c src/itoa_hex.c src/ft_strdup.c src/itoa_hex_point.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h libftprintf.h

%.o: %.c ${HEADER} Makefile
	$(CC) $(CFLAGS)  -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ${NAME}

re: fclean all

.PHONY:	all clean fclean re