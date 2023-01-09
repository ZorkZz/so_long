/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:14 by astachni          #+#    #+#             */
/*   Updated: 2023/01/09 18:07:57 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env	*w_pressed(t_perso_env *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img_ptr);
	mlx_do_sync(mlx->init);
	mlx->position[1] -= 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*a_pressed(t_perso_env *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img_ptr);
	mlx->position[0] -= 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*s_pressed(t_perso_env *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img_ptr);
	mlx->position[1] += 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

t_perso_env	*d_pressed(t_perso_env *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img_ptr);
	mlx->position[0] += 64;
	mlx->img_ptr = import_sprite_charactere(mlx);
	return (mlx);
}

int	event(int key, t_perso_env *mlx)
{
	if (key == W)
		mlx = w_pressed(mlx);
	else if (key == A)
		mlx =  a_pressed(mlx);
	else if (key == S)
		mlx = s_pressed(mlx);
	else if (key == D)
		mlx = d_pressed(mlx);
	else if (key == ESC)
	{
		close_mlx(mlx);
		ft_printf("%s\n", "fermeture de la fenetre");
	}
	else
		ft_printf("%s\n", "cle non reconnu");
	return (key);
}
