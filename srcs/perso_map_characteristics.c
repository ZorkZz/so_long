/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_map_characteristics.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:52:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/22 20:49:47 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	perso_charact(t_perso_env_map *env)
{
	env->perso.path = ft_strdup("./sprites/pikachu.xpm");
	env->perso.position[0] = 64;
	env->perso.position[1] = 64;
	env->perso.moov = 0;
	env->perso.img_ptr = NULL;
	return (*env);
}

t_perso_env_map	map_charact(t_perso_env_map *env)
{
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	env->map.position[0] = 0;
	env->map.position[1] = 0;
	return (*env);
}

t_perso_env_map	item_charact(t_perso_env_map *env)
{
	env->item.path = ft_strdup("./sprites/egg.xpm");
	env->item.itm_ptr = NULL;
	return (*env);
}

t_perso_env_map	exit_charac(t_perso_env_map *env)
{
	env->exit.path = ft_strdup("./sprites/obstacle2.xpm");
	env->exit.img_ptr = NULL;
	return (*env);
}

t_perso_env_map	add_charac(t_perso_env_map *env)
{
	env->enemy.path = ft_strdup("./sprites/pikachu.xpm");
	env->enemy.img_ptr = NULL;
	*env = item_charact(env);
	*env = map_charact(env);
	*env = perso_charact(env);
	*env = exit_charac(env);
	return (*env);
}
