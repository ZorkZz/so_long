/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:18 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 20:18:07 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	*import_sprite_charactere(t_var_env *mlx, char *path)
{
	void	*img;
	int		size[2];

	size[0] = 64;
	size[1] = 64;
	if (!mlx)
		return (error(0, "no mlx var"), NULL);
	if (!path)
		return (error(1, "no path"), NULL);
	if (!size)
		return (error(2, "no size"), NULL);
	img = mlx_xpm_file_to_image(mlx->init, path, &size[0], &size[1]);
	mlx_put_image_to_window(mlx->init, mlx->win, img, 0, 0);
	return (img);
}
