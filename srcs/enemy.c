/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:14 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/22 20:52:49 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_enemy(t_perso_env_map *env)
{
	env->enemy.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var"), NULL);
	if (!env->enemy.path)
		return (error(1, "no path"), NULL);
	if (!env->enemy.size)
		return (error(2, "no size"), NULL);
	env->enemy.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->enemy.path,
			&env->exit.size, &env->exit.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->enemy.img_ptr,
		env->enemy.position[0], env->enemy.position[1]);
	return (env);
}
