/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2023/02/25 17:11:39 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	import_sprite_charactere(t_game *env)
{
	if (!env->mlx.init || !env->mlx.win)
		error("no mlx var", env);
	if (!env->perso.path)
		error("no path", env);
	if (!env->perso.size)
		error("no size", env);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->perso.img_ptr,
		env->perso.position[0], env->perso.position[1]);
}

void	import_map(t_game *env, int choice)
{
	if (choice == 0)
	{
		if (!env->mlx.init || !env->mlx.win)
			error("no mlx var", env);
		if (!env->map.path)
			error("no path", env);
		if (!env->map.size)
			error("no size", env);
		mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->map.img_ptr,
			env->map.position[0], env->map.position[1]);
	}
	else if (choice == 1)
	{
		if (!env->mlx.init || !env->mlx.win)
			error("no mlx var", env);
		if (!env->map.path01)
			error("no path", env);
		if (!env->map.size)
			error("no size", env);
		mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->map.img_ptr01,
			env->map.position[0], env->map.position[1]);
	}
}

void	import_item(t_game *env)
{
	if (!env->mlx.init || !env->mlx.win)
		error("no mlx var", env);
	if (!env->item.path)
		error("no path", env);
	if (!env->item.size)
		error("no size", env);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->item.itm_ptr,
		env->item.position[0], env->item.position[1]);
}

void	import_exit(t_game *env)
{
	if (!env->mlx.init || !env->mlx.win)
		error("no mlx var", env);
	if (!env->exit.path)
		error("no path", env);
	if (!env->exit.size)
		error("no size", env);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->exit.img_ptr,
		env->exit.position[0], env->exit.position[1]);
}
