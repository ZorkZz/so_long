NAME = so_long

NAME_B = so_long_bonus

OBJS_DIR = objs/

SRCS = main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c srcs/read_map.c srcs/parse_map.c srcs/verify_moov_char.c srcs/enemy.c srcs/utils.c srcs/map_verif.c srcs/diffusion.c srcs/all_null.c

SRCS_BONUS = main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c srcs/read_map.c srcs/parse_map_bonus.c srcs/verify_moov_char.c srcs/enemy.c srcs/utils.c srcs/map_verif.c srcs/diffusion.c srcs/all_null.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)%.o)

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

all: mlx gnl printf $(NAME)

bonus:	mlx gnl printf $(NAME_B)

$(LIBS):	FORCE
	$(MAKE) -C libs/libft all

FORCE:

mlx:
		$(MAKE) -C $(PATH_MLX)

gnl:
		$(MAKE) -C libs/get_next_line

printf:
		$(MAKE) -C libs/ft_printf

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
			$(RM) $(NAME_B)
			@norminette main.c srcs/*.c header/*.h

$(NAME_B):	$(OBJS_BONUS) $(LIBS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(MLX_FLAGS) -o $(NAME_B)
			$(RM) $(NAME)
			@norminette main.c srcs/*.c header/*.h

clean:
	@make clean -C libs/libft
	@make clean -C libs/ft_printf
	@make clean -C $(PATH_MLX)
	@make clean -C libs/get_next_line
	$(RM) $(OBJS_BONUS)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	make fclean -C libs/get_next_line
	$(RM) $(NAME_B)
	$(RM) $(NAME)



re: fclean
	$(MAKE) all

.PHONY:	all bonus clean fclean re libft mlx gnl printf