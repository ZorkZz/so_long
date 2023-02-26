/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:12:13 by astachni          #+#    #+#             */
/*   Updated: 2023/02/26 17:28:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(t_game *env)
{
	free_map(env->map.map_char);
	free_all(env);
	mlx_destroy_window(env->mlx.init, env->mlx.win);
	mlx_destroy_display(env->mlx.init);
	free(env->mlx.init);
	exit(0);
	return (0);
}
