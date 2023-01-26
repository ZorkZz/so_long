/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:14 by astachni          #+#    #+#             */
/*   Updated: 2023/01/26 19:49:04 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_game	*w_pressed(t_game *env, int moov)
{
	env = verify_moov_char(env, moov);
	if (env->perso.can_moov == 1)
	{
		env->map.position[1] = env->perso.position[1];
		env->map.position[0] = env->perso.position[0];
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
		import_map(env, 0);
		env->perso.position[1] -= 64;
		import_sprite_charactere(env);
		env->perso.moov += 1;
		ft_printf("\nnumber of moov: %d\n", env->perso.moov);
	}
	else
		ft_printf("\nyou can't go up\n");
	return (env);
}

t_game	*s_pressed(t_game *env, int moov)
{
	env = verify_moov_char(env, moov);
	if (env->perso.can_moov == 1)
	{
		env->map.position[1] = env->perso.position[1];
		env->map.position[0] = env->perso.position[0];
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
		import_map(env, 0);
		env->perso.position[1] += 64;
		import_sprite_charactere(env);
		env->perso.moov += 1;
		ft_printf("\nnumber of moov: %d\n", env->perso.moov);
	}
	else
		ft_printf("\nyou can't go down\n");
	return (env);
}

t_game	*a_pressed(t_game *env, int moov)
{
	env = verify_moov_char(env, moov);
	if (env->perso.can_moov == 1)
	{	
		env->map.position[1] = env->perso.position[1];
		env->map.position[0] = env->perso.position[0];
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
		import_map(env, 0);
		env->perso.position[0] -= 64;
		import_sprite_charactere(env);
		env->perso.moov += 1;
		ft_printf("\nnumber of moov: %d\n", env->perso.moov);
	}
	else
		ft_printf("\nyou can't go left\n");
	return (env);
}

t_game	*d_pressed(t_game *env, int moov)
{
	env = verify_moov_char(env, moov);
	if (env->perso.can_moov == 1)
	{	
		env->map.position[1] = env->perso.position[1];
		env->map.position[0] = env->perso.position[0];
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
		import_map(env, 0);
		env->perso.position[0] += 64;
		import_sprite_charactere(env);
		env->perso.moov += 1;
		ft_printf("\nnumber of moov: %d\n", env->perso.moov);
	}
	else
		ft_printf("\nyou can't go right\n");
	return (env);
}

int	event(int key, t_game *env)
{
	if (key == W)
		env = w_pressed(env, 1);
	else if (key == S)
		env = s_pressed(env, 2);
	else if (key == A)
		env = a_pressed(env, 3);
	else if (key == D)
		env = d_pressed(env, 4);
	else if (key == ESC)
	{
		close_mlx(env);
		ft_printf("%s\n", "fermeture de la fenetre");
	}
	else
		ft_printf("%s\n", "cle non reconnu");
	return (key);
}
