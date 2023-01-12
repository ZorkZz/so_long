/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:14 by astachni          #+#    #+#             */
/*   Updated: 2023/01/12 18:52:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env	*w_pressed(t_perso_env *mlx, t_img *map)
{
	map->position[1] = mlx->position[1];
	map->position[0] = mlx->position[0];
	map->path = ft_strdup("./sprites/grass0.xpm");
	import_map(mlx, map);
	mlx->position[1] -= 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*a_pressed(t_perso_env *mlx, t_img *map)
{
	map->position[1] = mlx->position[1];
	map->position[0] = mlx->position[0];
	map->path = ft_strdup("./sprites/grass0.xpm");
	import_map(mlx, map);
	mlx->position[0] -= 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*s_pressed(t_perso_env *mlx, t_img *map)
{
	map->position[1] = mlx->position[1];
	map->position[0] = mlx->position[0];
	map->path = ft_strdup("./sprites/grass0.xpm");
	import_map(mlx, map);
	mlx->position[1] += 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*d_pressed(t_perso_env *mlx, t_img *map)
{
	map->position[1] = mlx->position[1];
	map->position[0] = mlx->position[0];
	map->path = ft_strdup("./sprites/grass0.xpm");
	import_map(mlx, map);
	mlx->position[0] += 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

int	event(int key, t_perso_env *mlx)
{
	t_img	img;

	img = map_charact(&img);
	if (key == W)
		mlx = w_pressed(mlx, &img);
	else if (key == A)
		mlx = a_pressed(mlx, &img);
	else if (key == S)
		mlx = s_pressed(mlx, &img);
	else if (key == D)
		mlx = d_pressed(mlx, &img);
	else if (key == ESC)
	{
		close_mlx(mlx);
		ft_printf("%s\n", "fermeture de la fenetre");
	}
	else
		ft_printf("%s\n", "cle non reconnu");
	return (key);
}
