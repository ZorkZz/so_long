NAME = so_long

OBJS_DIR = objs/

SRCS = srcs/main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/ft_printf/libftprintf.a libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

HEADER = header/so_long.h header/proto.h header/struct.h header/var.h

ifeq ($(shell uname -s), Linux)
$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	make -C libs/libft
	make -C libs/ft_printf
	make -C mlx_linux
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C mlx_linux
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	$(RM) $(NAME)

else
$(OBJS_DIR)%.o: %c $(HEADER) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
	make -C libs/libft
	make -C libs/ft_printf
	make -C mlx_linux
	$(CC) $(OBJS) $(LIBS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C mlx
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	$(RM) $(NAME)
endif

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re