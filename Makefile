NAME = so_long

SRCS = srcs/main.c srcs/open_close_mlx.c 

OBJS = $(SRCS:.c=.o)

LIBS = libs/ft_printf/libftprintf.a

CC = cc

RM = rm -f

HEADER = header/so_long.h

%.o: %.c $(HEADER) Makefile
	$(CC) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) -g $(OBJS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re