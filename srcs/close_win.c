/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:12:13 by astachni          #+#    #+#             */
/*   Updated: 2023/02/25 18:52:51 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(t_game *env)
{
	free_map(env->map.map_char);
	free_all(env);
	if (env->mlx.open_win == 1)
		mlx_destroy_window(env->mlx.init, env->mlx.win);
	if (env->mlx.init_mlx == 1)
	{
		mlx_destroy_display(env->mlx.init);
		free(env->mlx.init);
	}
	exit(0);
	return (0);
}
