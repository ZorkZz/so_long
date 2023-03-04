NAME = so_long

OBJS_DIR = objs/

SRCS = main.c srcs/error.c  srcs/close_win.c srcs/event.c srcs/import_sprite.c srcs/perso_map_characteristics.c srcs/free_all.c srcs/read_map.c srcs/parse_map.c srcs/verify_moov_char.c srcs/enemy.c srcs/utils.c srcs/map_verif.c srcs/diffusion.c srcs/all_null.c

LIBFT_SRCS = libs/libft/ft_isalpha.c libs/libft/ft_isdigit.c libs/libft/ft_isalnum.c libs/libft/ft_isascii.c libs/libft/ft_isprint.c libs/libft/ft_strlen.c libs/libft/ft_memset.c libs/libft/ft_bzero.c libs/libft/ft_memcpy.c libs/libft/ft_memmove.c libs/libft/ft_strlcpy.c libs/libft/ft_strlcat.c libs/libft/ft_toupper.c libs/libft/ft_tolower.c libs/libft/ft_strchr.c libs/libft/ft_strrchr.c libs/libft/ft_strncmp.c libs/libft/ft_memchr.c libs/libft/ft_memcmp.c libs/libft/ft_strnstr.c libs/libft/ft_atoi.c libs/libft/ft_calloc.c libs/libft/ft_strdup.c libs/libft/ft_substr.c libs/libft/ft_strjoin.c libs/libft/ft_strtrim.c libs/libft/ft_split.c libs/libft/ft_itoa.c libs/libft/ft_strmapi.c libs/libft/ft_striteri.c libs/libft/ft_putchar_fd.c  libs/libft/ft_putstr_fd.c libs/libft/ft_putendl_fd.c libs/libft/ft_putnbr_fd.c libs/libft/ft_strjoin.c libs/libft/libft.h libs/libft/Makefile

FT_PRINTF_SRCS = libs/ft_printf/ft_printf.c libs/ft_printf/src/ft_putchar_fd.c libs/ft_printf/src/ft_putstr_fd.c libs/ft_printf/src/print_func.c libs/ft_printf/src/ft_itoa.c libs/ft_printf/src/ft_itoa_u.c libs/ft_printf/src/itoa_hex.c libs/ft_printf/src/ft_strdup.c libs/ft_printf/src/itoa_hex_point.c libs/ft_printf/ft_printf.h libs/ft_printf/Makefile

GNL_SRCS = libs/get_next_line/get_next_line_utils.c libs/get_next_line/get_next_line.c libs/get_next_line/get_next_line.h libs/get_next_line/Makefile

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

all: libft mlx gnl printf $(NAME)

libft:
		$(MAKE) -C libs/libft bonus

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
			@norminette main.c srcs/*.c header/*.h

clean:
	@make clean -C libs/libft
	@make clean -C libs/ft_printf
	@make clean -C $(PATH_MLX)
	@make clean -C libs/get_next_line
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	make fclean -C libs/ft_printf
	make fclean -C libs/get_next_line
	$(RM) $(NAME)



re: fclean
	$(MAKE) all

.PHONY:	all clean fclean re libft mlx gnl printf