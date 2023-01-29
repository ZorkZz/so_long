NAME = so_long

OBJS_DIR = objs/

SRCS = main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c srcs/read_map.c srcs/parse_map.c srcs/verify_moov_char.c srcs/enemy.c srcs/utils.c srcs/map_verif.c srcs/map_is_finishable.c srcs/diffusion.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/ft_printf/libftprintf.a libs/get_next_line/get_next_line.a libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER = header/so_long.h header/proto.h header/struct.h header/var.h

ifeq ($(shell uname -s), Linux)
INCLUDE_FLAGS = -I/usr/include -Imlx_linux -O3

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

PATH_MLX = mlx_linux

else
INCLUDE_FLAGS =

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

PATH_MLX = mlx

endif

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make bonus -C libs/libft
	make -C libs/ft_printf
	make -C libs/get_next_line
	make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
	@norminette main.c srcs/*.c header/*.h

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C $(PATH_MLX)
	make clean -C libs/get_next_line
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	make fclean -C libs/get_next_line
	$(RM) $(NAME)


all: $(NAME)

re: fclean
	$(MAKE) all

.PHONY:	all clean fclean re