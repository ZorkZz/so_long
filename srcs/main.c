/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2023/01/02 23:11:40 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

//map == .ber

int	main(void)
{
	t_perso_env	mlx;
	t_img		map;

	mlx = perso_charact(&mlx);
	map = map_charact(&map);
	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	mlx.img_ptr = import_sprite_charactere(&mlx);
	if (!map.img_ptr || !mlx.img_ptr)
		return (error(4, "map or perso null"));
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &mlx);
	mlx_key_hook(mlx.win, event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
