/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:02:13 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 14:31:51 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(void)
{
	t_var_env		mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (-1);
	mlx.win = mlx_new_window(mlx.init, WIN_LENGHT, WIN_WIDTH, "so_long");
	if (mlx.win == NULL)
		return (-1);
	mlx_hook(mlx.win, 17, 1L << 2, close_mlx, &mlx);
	mlx_loop(mlx.init);
	return (0);
}
