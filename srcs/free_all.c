/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:01:20 by astachni          #+#    #+#             */
/*   Updated: 2023/02/24 17:25:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
** free structure
**
** @param int value 0	perso-> position and path
** @param int value 1	perso-> img_ptr and 0
** @param int value 2	map like 0
** @param int value 3	map like 1
** @param int value all	all
**
*/

void	destory_image(t_game *env)
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

void	other_free(t_game *env)
{
	if (env->enemy.path)
		free(env->enemy.path);
	if (env->exit.path)
		free(env->exit.path);
	if (env->item.path)
		free(env->item.path);
	if (env->enemy.img_ptr)
		free(env->enemy.img_ptr);
	if (env->exit.img_ptr)
		free(env->exit.img_ptr);
	if (env->item.itm_ptr)
		free(env->item.itm_ptr);
}

void	*free_all(int value, t_game *env)
{
	destory_image(env);
	if (value == 0)
		return (free(env->perso.path), NULL);
	else if (value == 1)
	{
		free(env->perso.path);
		free(env->perso.img_ptr);
		return (NULL);
	}
	else if (value == 2)
	{
		free(env->map.path);
		return (NULL);
	}
	else if (value == 3)
	{
		free(env->map.path);
		free(env->map.img_ptr);
		return (NULL);
	}
	other_free(env);
	return (free(env->perso.path), \
		free(env->perso.img_ptr), \
		free(env->map.img_ptr), free(env->map.path), NULL);
}
