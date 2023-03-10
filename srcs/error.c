/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:32:20 by astachni          #+#    #+#             */
/*   Updated: 2023/03/04 17:54:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	img_destroy(t_game *env)
{
	if (env->enemy.img_ptr)
		mlx_destroy_image(env->mlx.init, env->enemy.img_ptr);
	if (env->exit.img_ptr)
		mlx_destroy_image(env->mlx.init, env->exit.img_ptr);
	if (env->item.itm_ptr)
		mlx_destroy_image(env->mlx.init, env->item.itm_ptr);
	if (env->map.img_ptr)
		mlx_destroy_image(env->mlx.init, env->map.img_ptr);
	if (env->map.img_ptr01)
		mlx_destroy_image(env->mlx.init, env->map.img_ptr01);
	if (env->perso.img_ptr)
		mlx_destroy_image(env->mlx.init, env->perso.img_ptr);
}

int	error(char *message, t_game *env)
{
	img_destroy(env);
	ft_putstr_fd(message, 2);
	if (env->map.map_char)
		free_map(env->map.map_char);
	free_all(env);
	if (env->mlx.win != NULL)
		mlx_destroy_window(env->mlx.init, env->mlx.win);
	mlx_destroy_display(env->mlx.init);
	free(env->mlx.init);
	exit (1);
	return (0);
}

int	error_before_init(char *message, t_game *env)
{
	free_map(env->map.map_char);
	ft_putstr_fd(message, 2);
	exit (0);
	return (0);
}

int	error_map(char *message, t_game *env)
{
	free_map(env->map.map_char);
	ft_putstr_fd(message, 2);
	free_all(env);
	mlx_destroy_window(env->mlx.init, env->mlx.win);
	mlx_destroy_display(env->mlx.init);
	free(env->mlx.init);
	exit (0);
	return (0);
}
