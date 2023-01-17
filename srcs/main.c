/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2023/01/17 18:28:52 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

//map == .ber

int	main(int ac, char **av)
{
	t_perso_env_map	env;

	env = map_txt_to_char(ac, av, &env);
	if (env.map.map_char == NULL)
		return (error(5, "no pointer for image"));
	env = perso_charact(&env);
	env = map_charact(&env);
	env = item_charact(&env);
	env.mlx.init = mlx_init();
	if (env.mlx.init == NULL)
		return (-1);
	env.mlx.win = mlx_new_window(env.mlx.init, LENGHT, WIDTH, "so_long");
	if (env.mlx.win == NULL)
		return (-1);
	env = read_map(&env);
	env = push_item(&env);
	if (!env.map.img_ptr || !env.perso.img_ptr)
		return (error(4, "map or perso null"));
	mlx_hook(env.mlx.win, 17, 1L << 2, close_mlx, &env);
	mlx_key_hook(env.mlx.win, event, &env);
	mlx_loop(env.mlx.init);
	return (0);
}
