/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:01:20 by astachni          #+#    #+#             */
/*   Updated: 2023/02/25 18:56:31 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destory_image(t_game *env)
{
	if (env && env->mlx.init_sprite == 1)
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

void	free_all(t_game *env)
{
	destory_image(env);
	if (env->perso.path)
		free(env->perso.path);
	if (env->map.path)
		free(env->map.path);
	if (env->map.path01)
		free(env->map.path01);
	if (env->enemy.path)
		free(env->enemy.path);
	if (env->exit.path)
		free(env->exit.path);
	if (env->item.path)
		free(env->item.path);
}
