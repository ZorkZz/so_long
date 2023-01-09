NAME = so_long

OBJS_DIR = ./

SRCS = srcs/main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/ft_printf/libftprintf.a libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

HEADER = header/so_long.h header/proto.h header/struct.h header/var.h

MAKE_FT_PRINTF = $(MAKE) -C libs/ft_printf/

ifeq ($(shell uname -s), Linux)
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
else
$(OBJS_DIR)%.o: %c $(HEADER) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
endif

all: $(NAME)
	$(MAKE_FT_PRINTF)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re