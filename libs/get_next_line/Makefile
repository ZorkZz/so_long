# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:44:53 by astachni          #+#    #+#              #
#    Updated: 2023/01/12 17:00:18 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line_utils.c get_next_line.c

OBJS = $(SRCS:%.c=%.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

HEADER = get_next_line.h get_next.h

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS)  -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ${NAME}

re: fclean all

.PHONY:	all clean fclean re