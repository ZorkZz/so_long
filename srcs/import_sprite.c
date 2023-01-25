/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2023/01/25 20:40:30 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_sprite_charactere(t_game *env)
{
	env->perso.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var", env), NULL);
	if (!env->perso.path)
		return (error(1, "no path", env), NULL);
	if (!env->perso.size)
		return (error(2, "no size", env), NULL);
	env->perso.img_ptr = mlx_xpm_file_to_image(env->mlx.init, \
		env->perso.path, &env->perso.size, &env->perso.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->perso.img_ptr,
		env->perso.position[0], env->perso.position[1]);
	return (env->perso.img_ptr);
}

void	*import_map(t_game *env)
{
	env->map.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var", env), NULL);
	if (!env->map.path)
		return (error(1, "no path", env), NULL);
	if (!env->map.size)
		return (error(2, "no size", env), NULL);
	env->map.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->map.path,
			&env->map.size, &env->map.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->map.img_ptr,
		env->map.position[0], env->map.position[1]);
	return (env->map.img_ptr);
}

void	*import_item(t_game *env)
{
	env->item.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var", env), NULL);
	if (!env->item.path)
		return (error(1, "no path", env), NULL);
	if (!env->item.size)
		return (error(2, "no size", env), NULL);
	env->item.itm_ptr = mlx_xpm_file_to_image(env->mlx.init, env->item.path,
			&env->item.size, &env->item.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->item.itm_ptr,
		env->item.position[0], env->item.position[1]);
	return (env->item.itm_ptr);
}

void	*import_exit(t_game *env)
{
	env->exit.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var", env), NULL);
	if (!env->exit.path)
		return (error(1, "no path", env), NULL);
	if (!env->exit.size)
		return (error(2, "no size", env), NULL);
	env->exit.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->exit.path,
			&env->exit.size, &env->exit.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->exit.img_ptr,
		env->exit.position[0], env->exit.position[1]);
	return (env->exit.img_ptr);
}
