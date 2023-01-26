/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_map_characteristics.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:52:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/26 22:08:51 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_game	perso_charact(t_game *env)
{
	env->perso.size = 64;
	env->perso.path = ft_strdup("./sprites/pikachu.xpm");
	env->perso.position[0] = 64;
	env->perso.position[1] = 64;
	env->perso.moov = 0;
	env->perso.img_ptr = NULL;
	env->perso.img_ptr = mlx_xpm_file_to_image(env->mlx.init, \
		env->perso.path, &env->perso.size, &env->perso.size);
	return (*env);
}

t_game	map_charact(t_game *env)
{
	env->map.size = 64;
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	env->map.path01 = ft_strdup("./sprites/obstacle0.xpm");
	env->map.position[0] = 0;
	env->map.position[1] = 0;
	env->map.img_ptr = NULL;
	env->map.img_ptr01 = NULL;
	env->map.img_ptr01 = mlx_xpm_file_to_image(env->mlx.init, env->map.path01,
			&env->map.size, &env->map.size);
	env->map.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->map.path,
			&env->map.size, &env->map.size);
	return (*env);
}

t_game	item_charact(t_game *env)
{
	env->item.size = 64;
	env->item.path = ft_strdup("./sprites/egg.xpm");
	env->item.itm_ptr = NULL;
	env->item.itm_ptr = mlx_xpm_file_to_image(env->mlx.init, env->item.path,
			&env->item.size, &env->item.size);
	return (*env);
}

t_game	exit_charac(t_game *env)
{
	env->exit.size = 64;
	env->exit.path = ft_strdup("./sprites/exit.xpm");
	env->exit.img_ptr = NULL;
	env->exit.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->exit.path,
			&env->exit.size, &env->exit.size);
	return (*env);
}

t_game	add_charac(t_game *env)
{
	env->enemy.size = 64;
	env->enemy.path = ft_strdup("./sprites/mewtoo.xpm");
	env->enemy.img_ptr = NULL;
	env->enemy.img_ptr = mlx_xpm_file_to_image(env->mlx.init, env->enemy.path,
			&(env->enemy.size), &(env->enemy.size));
	*env = item_charact(env);
	*env = map_charact(env);
	*env = perso_charact(env);
	*env = exit_charac(env);
	return (*env);
}
