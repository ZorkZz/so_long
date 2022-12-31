/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 16:08:58 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// mettre la struct mlx et perso en 1

int	main(void)
{
	t_var_env	mlx;
	t_perso		perso;
	t_img		map;

	perso = perso_charact(&perso);
	map = map_charact(&map);
	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	perso.img_ptr = import_sprite_charactere(&mlx, &perso);
	if (!map.img_ptr || !perso.img_ptr)
		return (error(4, "map or perso null"));
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &mlx);
	mlx_key_hook(mlx.win, event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
