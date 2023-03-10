/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:12:13 by astachni          #+#    #+#             */
/*   Updated: 2023/03/04 17:10:39 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(t_game *env)
{
	if (env->map.map_char)
		free_map(env->map.map_char);
	free_all(env);
	if (env->mlx.win != NULL)
		mlx_destroy_window(env->mlx.init, env->mlx.win);
	mlx_destroy_display(env->mlx.init);
	free(env->mlx.init);
	exit(0);
	return (0);
}
