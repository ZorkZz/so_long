/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:14 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/25 20:41:13 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_enemy(t_game *env)
{
	env->enemy.size = 64;
	if (!env->mlx.init || !env->mlx.win)
		return (error(0, "no mlx var", env), NULL);
	if (!env->enemy.path)
		return (error(1, "no path", env), NULL);
	if (!env->enemy.size)
		return (error(2, "no size", env), NULL);
	env->enemy.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->enemy.path,
			&env->exit.size, &env->exit.size);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->enemy.img_ptr,
		env->enemy.position[0], env->enemy.position[1]);
	return (env);
}
