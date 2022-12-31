/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 02:55:15 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(void)
{
	t_var_env	mlx;
	t_perso		perso;
	t_img		map;

	perso.path = ft_strdup("./sprites/pikachu.xpm");
	perso.position[0] = 64;
	perso.position[1] = 64;
	map.path = ft_strdup("./sprites/obstacle0.xpm");
	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	map.img_ptr = import_map(&mlx, &map);
	perso.img_ptr = import_sprite_charactere(&mlx, &perso);
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &perso);
	mlx_key_hook(mlx.win, event, &mlx);
	mlx_loop(mlx.init);
	free(perso.path);
	return (0);
}
