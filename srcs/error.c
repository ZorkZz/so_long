/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:32:20 by astachni          #+#    #+#             */
/*   Updated: 2023/02/26 17:26:09 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_destroy(t_game *env)
{
	if (env->mlx.init_sprite == 1)
	{
		if (env->enemy.img_ptr)
			mlx_destroy_image(env->mlx.init, env->enemy.img_ptr);
		if (env->exit.img_ptr)
			mlx_destroy_image(env->mlx.init, env->exit.img_ptr);
		if (env->item.itm_ptr)
			mlx_destroy_image(env->mlx.init, env->item.itm_ptr);
		if (env->map.img_ptr)
			mlx_destroy_image(env->mlx.init, env->map.img_ptr);
		if (env->map.img_ptr01)
			mlx_destroy_image(env->mlx.init, env->map.img_ptr01);
		if (env->perso.img_ptr)
			mlx_destroy_image(env->mlx.init, env->perso.img_ptr);
	}
}

int	error(char *message, t_game *env)
{
	free_map(env->map.map_char);
	img_destroy(env);
	ft_putstr_fd(message, 2);
	close_mlx(env);
	exit (1);
	return (0);
}

int	error_before_init(char *message, t_game *env)
{
	free_map(env->map.map_char);
	ft_putstr_fd(message, 2);
	exit (0);
	return (0);
}
