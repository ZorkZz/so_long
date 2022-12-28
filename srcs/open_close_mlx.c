/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:32:20 by astachni          #+#    #+#             */
/*   Updated: 2022/12/28 23:47:49 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	open_win(t_var *mlx_ptr, t_var *win_ptr, char *title)
{
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (-1);
	win_ptr = mlx_new_window(mlx_ptr, WIN_LENGHT, WIN_WIDTH, "bonjour");
	if (win_ptr == NULL)
		return (-1);
	mlx_loop(mlx_ptr);
	return (0);
}

int	close_win()
{
	return (0);
}
