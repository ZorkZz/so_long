/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_map_characteristics.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:52:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/17 20:02:12 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	perso_charact(t_perso_env_map *env)
{
	env->perso.path = ft_strdup("./sprites/pikachu.xpm");
	env->perso.position[0] = 64;
	env->perso.position[1] = 64;
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
	return (*env);
}
