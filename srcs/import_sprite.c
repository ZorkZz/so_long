/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 20:55:38 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_sprite_charactere(t_perso_env_map *env)
{
	env->perso.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var"), NULL);
	if (!env->perso.path)
		return (error(1, "no path"), NULL);
	if (!env->perso.size)
		return (error(2, "no size"), NULL);
	env->perso.img_ptr = mlx_xpm_file_to_image(env->mlx.init, \
		env->perso.path, &env->perso.size, &env->perso.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->perso.img_ptr,
		env->perso.position[0], env->perso.position[1]);
	return (env->perso.img_ptr);
}

void	*import_map(t_perso_env_map *env)
{
	env->map.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var"), NULL);
	if (!env->map.path)
		return (error(1, "no path"), NULL);
	if (!env->map.size)
		return (error(2, "no size"), NULL);
	env->map.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->map.path,
			&env->map.size, &env->map.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->map.img_ptr,
		env->map.position[0], env->map.position[1]);
	return (env->map.img_ptr);
}
