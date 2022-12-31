/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 14:56:29 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include <fcntl.h>

void	*import_sprite_charactere(t_var_env *mlx, t_perso *perso)
{
	perso->size = 64;
	if (!mlx)
		return (error(0, "no mlx var"), NULL);
	if (!perso->path)
		return (error(1, "no path"), NULL);
	if (!perso->size)
		return (error(2, "no size"), NULL);
	perso->img_ptr = mlx_xpm_file_to_image(mlx->init, perso->path,
			&perso->size, &perso->size);
	mlx_put_image_to_window(mlx->init, mlx->win, perso->img_ptr,
		perso->position[0], perso->position[1]);
	return (perso->img_ptr);
}

void	*import_map(t_var_env *mlx, t_img *map)
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
