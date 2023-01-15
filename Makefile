NAME = so_long

OBJS_DIR = 

SRCS = srcs/main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c srcs/read_map.c srcs/parse_map.c srcs/verify_moov_char.c

OBJS = $(SRCS:%.c=%.o)

LIBS = libs/ft_printf/libftprintf.a libs/get_next_line/get_next_line.a libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

MLX_MAC_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit



RM = rm -f

HEADER = header/so_long.h header/proto.h header/struct.h header/var.h

ifeq ($(shell uname -s), Linux)
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	make bonus -C libs/libft
	make -C libs/ft_printf
	make -C libs/get_next_line
	make -C mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C mlx_linux
	make clean -C libs/get_next_line
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	make fclean -C libs/get_next_line
	$(RM) $(NAME)

else
%.o: %c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(MLX_MAC_FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make -C libs/get_next_line
	make bonus -C libs/libft
	make -C libs/ft_printf
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_MAC_FLAGS) -o $(NAME)

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C mlx
	make clean -C libs/get_next_line
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	make fclean -C libs/get_next_line
	$(RM) $(NAME)
endif

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re