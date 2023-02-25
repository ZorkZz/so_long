/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:24:14 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/25 17:12:10 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	import_enemy(t_game *env)
{
	if (!env->mlx.init || !env->mlx.win)
		error("no mlx var", env);
	if (!env->enemy.path)
		error("no path", env);
	if (!env->enemy.size)
		error("no size", env);
	mlx_put_image_to_window(env->mlx.init, env->mlx.win, env->enemy.img_ptr,
		env->enemy.position[0], env->enemy.position[1]);
}
