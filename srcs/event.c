/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:14 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 20:52:55 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	*w_pressed(t_perso_env_map *env)
{
	env->map.position[1] = env->perso.position[1];
	env->map.position[0] = env->perso.position[0];
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	import_map(env);
	env->perso.position[1] -= 64;
	env->perso.img_ptr = import_sprite_charactere(env);
	return (env);
}

t_perso_env_map	*a_pressed(t_perso_env_map *env)
{
	env->map.position[1] = env->perso.position[1];
	env->map.position[0] = env->perso.position[0];
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	import_map(env);
	env->perso.position[0] -= 64;
	env->perso.img_ptr = import_sprite_charactere(env);
	return (env);
}

t_perso_env_map	*s_pressed(t_perso_env_map *env)
{
	env->map.position[1] = env->perso.position[1];
	env->map.position[0] = env->perso.position[0];
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	import_map(env);
	env->perso.position[1] += 64;
	env->perso.img_ptr = import_sprite_charactere(env);
	return (env);
}

t_perso_env_map	*d_pressed(t_perso_env_map *env)
{
	env->map.position[1] = env->perso.position[1];
	env->map.position[0] = env->perso.position[0];
	env->map.path = ft_strdup("./sprites/grass0.xpm");
	import_map(env);
	env->perso.position[0] += 64;
	env->perso.img_ptr = import_sprite_charactere(env);
	return (env);
}

int	event(int key, t_perso_env_map *env)
{
	if (key == W)
		env = w_pressed(env);
	else if (key == A)
		env = a_pressed(env);
	else if (key == S)
		env = s_pressed(env);
	else if (key == D)
		env = d_pressed(env);
	else if (key == ESC)
	{
		close_mlx(env);
		ft_printf("%s\n", "fermeture de la fenetre");
	}
	else
		ft_printf("%s\n", "cle non reconnu");
	return (key);
}
