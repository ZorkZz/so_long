/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2023/01/02 23:21:39 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_sprite_charactere(t_perso_env *mlx)
{
	mlx->size = 64;
	if (!mlx)
		return (error(0, "no mlx var"), NULL);
	if (!mlx->path)
		return (error(1, "no path"), NULL);
	if (!mlx->size)
		return (error(2, "no size"), NULL);
	mlx->img_ptr = mlx_xpm_file_to_image(mlx->init, mlx->path,
			&mlx->size, &mlx->size);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img_ptr,
		mlx->position[0], mlx->position[1]);
	return (mlx->img_ptr);
}

void	*import_map(t_perso_env *mlx, t_img *map)
{

	map->size = 64;
	if (!mlx)
		return (error(0, "no mlx var"), NULL);
	if (!map->path)
		return (error(1, "no path"), NULL);
	if (!map->size)
		return (error(2, "no size"), NULL);
	map->img_ptr = mlx_xpm_file_to_image(mlx->init, map->path,
			&map->size, &map->size);
	mlx_put_image_to_window(mlx->init, mlx->win, map->img_ptr,
		map->position[0], map->position[1]);
	return (map->img_ptr);
}
