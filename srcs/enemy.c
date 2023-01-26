/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:14 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/26 19:51:56 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	import_enemy(t_game *env)
{
	if (!env->mlx.init || !env->mlx.win)
		error(0, "no mlx var", env);
	if (!env->enemy.path)
		error(1, "no path", env);
	if (!env->enemy.size)
		error(2, "no size", env);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->enemy.img_ptr,
		env->enemy.position[0], env->enemy.position[1]);
}
