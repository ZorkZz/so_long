/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/29 18:59:43 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(int keycode, t_var_env mlx)
{
	mlx_destroy_window(mlx.init, mlx.win);
	return (0);
}


int	main(void)
{
	t_var_env		mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "bonjour");
	if (mlx.win == NULL)
		return (-1);
	mlx_key_hook(mlx.win, close_mlx, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
