/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 16:13:39 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_sprite(t_var_env *mlx, char *path, int *size)
{
	void	*img;

	if (!mlx)
		return (error(0, "no mlx var"), NULL);
	if (!path)
		return (error(1, "no path"), NULL);
	if (!size)
		return (error(2, "no size"), NULL);
	ft_printf("mlx adress: %p\n", mlx->init);
	img = mlx_xpm_file_to_image(mlx->init, "./imgs/sb.xpm", &size[0], &size[1]);
	ft_printf("%p", img);
	return (img);
}

int	main(void)
{
	t_var_env	mlx;
	int			*size = {1920, 1080};

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &mlx);
	mlx_key_hook(mlx.win, event, &mlx);
	//import_sprite(&mlx, "./imgs/sb.xpm", size);
	mlx_loop(mlx.init);
	return (0);
}
