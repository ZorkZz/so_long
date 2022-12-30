/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 20:18:29 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(void)
{
	t_var_env	mlx;
	t_character	character;

	character.path = "./sprites/pikachu.xpm";
	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	character.img_ptr = import_sprite_charactere(&mlx, character.path);
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &mlx);
	mlx_key_hook(mlx.win, event, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
